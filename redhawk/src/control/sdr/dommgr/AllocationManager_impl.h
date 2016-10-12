/*
* This file is protected by Copyright. Please refer to the COPYRIGHT file 
* distributed with this source distribution.
* 
* This file is part of REDHAWK core.
* 
* REDHAWK core is free software: you can redistribute it and/or modify it 
* under the terms of the GNU Lesser General Public License as published by the 
* Free Software Foundation, either version 3 of the License, or (at your 
* option) any later version.
* 
* REDHAWK core is distributed in the hope that it will be useful, but WITHOUT 
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License 
* for more details.
* 
* You should have received a copy of the GNU Lesser General Public License 
* along with this program.  If not, see http://www.gnu.org/licenses/.
*/


#ifndef __ALLOCATIONMANAGER__IMPL
#define __ALLOCATIONMANAGER__IMPL

#include <string>
#include <list>
#include <sstream>

#include <ossie/CF/cf.h>
#include <ossie/debug.h>
#include <ossie/FileStream.h>
#include <ossie/prop_utils.h>
#include <ossie/DeviceManagerConfiguration.h>
#include "DomainManager_impl.h"

class AllocationManager_impl: public virtual POA_CF::AllocationManager
{
    ENABLE_LOGGING
    
    public:
        AllocationManager_impl (DomainManager_impl* domainManager);
        ~AllocationManager_impl ();
        
        CF::AllocationManager::AllocationResponseSequence* allocate(const CF::AllocationManager::AllocationRequestSequence &requests) throw (CF::AllocationManager::AllocationError);
        
        /* Allocates a set of dependencies only inside the local Domain */
        CF::AllocationManager::AllocationResponseSequence* allocateLocal(const CF::AllocationManager::AllocationRequestSequence &requests, const char* domainName) throw (CF::AllocationManager::AllocationError);
        
        /* Deallocates a set of allocations */
        void deallocate(const CF::AllocationManager::allocationIDSequence &allocationIDs) throw (CF::AllocationManager::InvalidAllocationId);
        
        /* Returns all current allocations on all Domains */
        CF::AllocationManager::AllocationStatusSequence* allocations(const CF::AllocationManager::allocationIDSequence &allocationIDs) throw (CF::AllocationManager::InvalidAllocationId);
        
        /* Returns all current allocations that were made through the Allocation Manager that have not been deallocated */
        CF::AllocationManager::AllocationStatusSequence* localAllocations(const CF::AllocationManager::allocationIDSequence &allocationIDs) throw (CF::AllocationManager::InvalidAllocationId);
        
        /* Returns all devices in all Domains that can be seen by any Allocation Manager seen by the local Allocation Manager */
        CF::AllocationManager::DeviceLocationSequence* allDevices();
        
        /* Returns all devices after policy is applied by any Allocation Manager seen by the local Allocation Manager */
        CF::AllocationManager::DeviceLocationSequence* authorizedDevices();
        
        /* Returns all devices that are located within the local Domain */
        CF::AllocationManager:: DeviceLocationSequence* localDevices();
        
        /* Returns all devices that are located within the local Domain */
        CF::DomainManager_ptr domainMgr();

        /* Allocates a set of dependencies for deployment; not part of the CORBA API */
        ossie::AllocationResult allocateDeployment(const std::string& requestID, const CF::Properties& allocationProperties, ossie::DeviceList& devices, const std::vector<std::string>& processorDeps, const std::vector<ossie::SPD::NameVersionPair>& osDeps);

        /* Deallocates a set of allocations */
        template <class Iterator>
        void deallocate(Iterator first, const Iterator end)
        {
            CF::AllocationManager::allocationIDSequence invalidAllocations;
            invalidAllocations.length(0);

            boost::recursive_mutex::scoped_lock lock(allocationAccess);
            for (; first != end; ++first) {
                const std::string allocationId(*first);
                if (!deallocateSingle(allocationId)) {
                    LOG_TRACE(AllocationManager_impl, "Invalid allocation ID " << allocationId);
                    ossie::corba::push_back(invalidAllocations, allocationId.c_str());
                }
            }

            this->_domainManager->updateLocalAllocations(this->_allocations);
            this->_domainManager->updateRemoteAllocations(this->_remoteAllocations);
            if (invalidAllocations.length() != 0) {
                throw CF::AllocationManager::InvalidAllocationId(invalidAllocations);
            }
        }

        // Local interface for persistance support
        void restoreLocalAllocations(const ossie::AllocationTable& localAllocations);
        void restoreRemoteAllocations(const ossie::RemoteAllocationTable& remoteAllocations);

        void restoreAllocations(ossie::AllocationTable& ref_allocations, std::map<std::string, CF::AllocationManager_var> &ref_remoteAllocations);

    private:
        CF::AllocationManager::AllocationResponseSequence* allocateDevices(const CF::AllocationManager::AllocationRequestSequence &requests, ossie::DeviceList& devices, const std::string& domainName);

        std::pair<ossie::AllocationType*,ossie::DeviceList::iterator> allocateRequest(const std::string& requestID, const CF::Properties& allocationProperties, ossie::DeviceList& devices, const std::vector<std::string>& processorDeps, const std::vector<ossie::SPD::NameVersionPair>& osDeps, const std::string& domainName);

        bool checkDeviceMatching(ossie::Properties& _prf, CF::Properties& externalProps, const CF::Properties& dependencyPropertiesFromComponent, const std::vector<std::string>& processorDeps, const std::vector<ossie::SPD::NameVersionPair>& osDeps);

        bool checkMatchingProperty(const ossie::Property* property, const CF::DataType& dependency);

        bool allocateDevice(const CF::Properties& requestedProperties, ossie::DeviceNode& device, CF::Properties& allocatedProperties, const std::vector<std::string>& processorDeps, const std::vector<ossie::SPD::NameVersionPair>& osDeps);
        void partitionProperties(const CF::Properties& properties, std::vector<CF::Properties>& outProps);

        bool completeAllocations(CF::Device_ptr device, const std::vector<CF::Properties>& duplicates);

        bool deallocateSingle(const std::string& allocationID);
        bool deallocateLocal(const std::string& allocationID);
        bool deallocateRemote(const std::string& allocationID);

        DomainManager_impl* _domainManager;
        ossie::AllocationTable _allocations;
        ossie::RemoteAllocationTable _remoteAllocations;
        void unfilledRequests(CF::AllocationManager::AllocationRequestSequence &requests, const CF::AllocationManager::AllocationResponseSequence &result);
    
    protected:
        boost::recursive_mutex allocationAccess;
        
};                  /* END CLASS DEFINITION AllocationManager */
#endif              /* __ALLOCATIONMANAGER__IMPL */
