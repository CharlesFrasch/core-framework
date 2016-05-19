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
// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#include "sad-pimpl.h"
#include "ossie/debug.h"
#include "ossie/ossieSupport.h"
#include <sstream>

CREATE_LOGGER(sad_parser);

namespace sad
{
  // softwareassembly_pimpl
  //

  void softwareassembly_pimpl::
  pre ()
  {
      _sad.reset(new ossie::SoftwareAssembly::SAD());
  }

  void softwareassembly_pimpl::
  description (const ::std::string& description)
  {
    // TODO
    //
  }

  void softwareassembly_pimpl::
  componentfiles (const ::std::vector<ossie::ComponentFile>& componentfiles)
  {
      _sad->componentfiles = componentfiles;
  }

  void softwareassembly_pimpl::
  partitioning (const ossie::SoftwareAssembly::Partitioning& partitioning)
  {
      _sad->partitioning = partitioning;
  }

  void softwareassembly_pimpl::
  assemblycontroller (const ::std::string& assemblycontroller)
  {
      _sad->assemblycontroller = assemblycontroller;
  }

  void softwareassembly_pimpl::
  connections (const ::std::vector<ossie::Connection>& connections)
  {
      _sad->connections = connections;
  }

  void softwareassembly_pimpl::
  externalports (const ::std::vector<ossie::SoftwareAssembly::Port>& externalports)
  {
      _sad->externalports = externalports;
  }

  void softwareassembly_pimpl::
  externalproperties (const ::std::vector<ossie::SoftwareAssembly::Property>& externalproperties)
  {
      _sad->externalproperties = externalproperties;
  }

  void softwareassembly_pimpl::
  usesdevicedependencies (const ::std::vector<ossie::SoftwareAssembly::UsesDevice>& usesdevices)
  {
      _sad->usesdevice = usesdevices;
  }

  void softwareassembly_pimpl::
  id (const ::std::string& id)
  {
      _sad->id = id;
  }

  void softwareassembly_pimpl::
  name (const ::std::string& name)
  {
      _sad->name = name;
  }

  ::std::auto_ptr<ossie::SoftwareAssembly::SAD> softwareassembly_pimpl::
  post_softwareassembly ()
  {
      return _sad;
  }

  // componentfiles_pimpl
  //

  void componentfiles_pimpl::
  pre ()
  {
      componentFiles.clear();
  }

  void componentfiles_pimpl::
  componentfile (const ::ossie::ComponentFile& componentfile)
  {
      componentFiles.push_back(componentfile);
  }

  ::std::vector<ossie::ComponentFile> componentfiles_pimpl::
  post_componentfiles ()
  {
    return componentFiles;
  }

  // componentfile_pimpl
  //

  void componentfile_pimpl::
  pre ()
  {
      componentFile.reset(new ossie::ComponentFile());
  }

  void componentfile_pimpl::
  localfile (const ::std::string& localfile)
  {
    assert(componentFile.get() != 0);
    componentFile->filename = localfile;
  }

  void componentfile_pimpl::
  id (const ::std::string& id)
  {
    assert(componentFile.get() != 0);
    componentFile->id = id;
  }

  void componentfile_pimpl::
  type (const ::std::string& type)
  {
    assert(componentFile.get() != 0);
    componentFile->type = type;
  }

  ::ossie::ComponentFile componentfile_pimpl::
  post_componentfile ()
  {
    assert(componentFile.get() != 0);
    return *componentFile;
  }

  // localfile_pimpl
  //

  void localfile_pimpl::
  pre ()
  {
    filename = "";
  }

  void localfile_pimpl::
  name (const ::std::string& name)
  {
    filename = name;
  }

  ::std::string localfile_pimpl::
  post_localfile ()
  {
    return filename;
  }

  // partitioning_pimpl
  //

  void partitioning_pimpl::
  pre ()
  {
    partitioning.reset(new ossie::SoftwareAssembly::Partitioning());
  }

  void partitioning_pimpl::
  componentplacement (const ::ossie::ComponentPlacement& componentplacement)
  {
    partitioning->placements.push_back(componentplacement);
  }

  void partitioning_pimpl::
  hostcollocation (const ossie::SoftwareAssembly::HostCollocation& hostcollocation)
  {
    LOG_TRACE(sad_parser, "Adding host collocations");
    partitioning->collocations.push_back(hostcollocation);
  }

  ossie::SoftwareAssembly::Partitioning partitioning_pimpl::
  post_partitioning ()
  {
    return *partitioning;
  }

  // componentplacement_pimpl
  //

  void componentplacement_pimpl::
  pre ()
  {
    componentPlacement.instantiations.clear();
    componentPlacement = ossie::ComponentPlacement();
  }

  void componentplacement_pimpl::
  componentfileref (const ::std::string& componentfileref)
  {
    componentPlacement._componentFileRef = componentfileref;
  }

  void componentplacement_pimpl::
  componentinstantiation (const ::ossie::ComponentInstantiation& componentinstantiation)
  {
    componentPlacement.instantiations.push_back(componentinstantiation);
  }

  const ::ossie::ComponentPlacement& componentplacement_pimpl::
  post_componentplacement ()
  {
    return componentPlacement;
  }

  // componentfileref_pimpl
  //

  void componentfileref_pimpl::
  pre ()
  {
    _refid = "";
  }

  void componentfileref_pimpl::
  refid (const ::std::string& refid)
  {
    this->_refid = refid;
  }

  ::std::string componentfileref_pimpl::
  post_componentfileref ()
  {
    return _refid;
  }

  // componentinstantiation_pimpl
  //

  void componentinstantiation_pimpl::
  pre ()
  {
    componentInstantiation.properties.clear();
    componentInstantiation = ::ossie::ComponentInstantiation();
  }
  
  void componentinstantiation_pimpl::
  startorder (const ::std::string& startorder)
  {
    componentInstantiation._startOrder = startorder;
  }

  void componentinstantiation_pimpl::
  usagename (const ::std::string& usagename)
  {
    componentInstantiation.usageName = usagename;
  }

  void componentinstantiation_pimpl::
  componentproperties ( const ossie::ComponentPropertyList& componentproperties)
  {
    componentInstantiation.properties = componentproperties;
  }

  void componentinstantiation_pimpl::
  findcomponent (const ::std::string& namingservicename)
  {
    LOG_TRACE(sad_parser, "setting instantiation naming service name " << namingservicename);
    componentInstantiation.namingservicename = namingservicename;
  }

  void componentinstantiation_pimpl::
  id (const ::std::string& id)
  {
    componentInstantiation.instantiationId = id;
  }

  void componentinstantiation_pimpl::
  affinity (const ossie::ComponentInstantiation::AffinityProperties& affinityProperties)
  {
    LOG_TRACE(sad_parser, "affinity properties");
    componentInstantiation.affinityProperties= affinityProperties;
  }

  void componentinstantiation_pimpl::loggingconfig ( const ossie::ComponentInstantiation::LoggingConfig& log_cfg )
  {
    componentInstantiation.loggingConfig = log_cfg;
  }


  const ::ossie::ComponentInstantiation& componentinstantiation_pimpl::
  post_componentinstantiation ()
  {
    return componentInstantiation;
  }

  void affinity_pimpl::
  pre ()
  {
    affinityProperties.clear();
  }

  void affinity_pimpl::
  simpleref (const ossie::SimplePropertyRef& simpleref)
  {
    LOG_TRACE(sad_parser, "Adding simpleref ");
    affinityProperties.push_back(simpleref.clone());
  }

  void affinity_pimpl::
  simplesequenceref (const ossie::SimpleSequencePropertyRef& simplesequenceref)
  {
    LOG_TRACE(sad_parser, "Adding simplesequenceref");
    affinityProperties.push_back(simplesequenceref.clone());
  }

  void affinity_pimpl::
  structref (const ossie::StructPropertyRef& structref)
  {
    LOG_TRACE(sad_parser, "Adding structref");
    affinityProperties.push_back(structref.clone());
  }

  void affinity_pimpl::
  structsequenceref (const ossie::StructSequencePropertyRef& structsequenceref)
  {
    LOG_TRACE(sad_parser, "Adding structsequenceref");
    affinityProperties.push_back(structsequenceref.clone());
  }

  const ossie::ComponentInstantiation::AffinityProperties& affinity_pimpl::post_affinity ()
  {
    return affinityProperties;
  }

  //
  // loggingconfig_pimpl
  //
  void loggingconfig_pimpl::pre ()
  {
    info = ossie::ComponentInstantiation::LoggingConfig("","");
  }

  void loggingconfig_pimpl::level ( const ::std::string &v )
  {
    info.second=v;
  }

  const ossie::ComponentInstantiation::LoggingConfig& loggingconfig_pimpl::post_loggingconfig ( )
  {
    info.first = this->post_string();
    return info;
  }

  // componentproperties_pimpl
  //

  void componentproperties_pimpl::
  pre ()
  {
    componentProperties.clear();
  }

  void componentproperties_pimpl::
  simpleref (const ossie::SimplePropertyRef& simpleref)
  {
    componentProperties.push_back(simpleref.clone());
  }

  void componentproperties_pimpl::
  simplesequenceref (const ossie::SimpleSequencePropertyRef& simplesequenceref)
  {
    componentProperties.push_back(simplesequenceref.clone());
  }

  void componentproperties_pimpl::
  structref (const ossie::StructPropertyRef& structref)
  {
    componentProperties.push_back(structref.clone());
  }

  void componentproperties_pimpl::
  structsequenceref ( const ossie::StructSequencePropertyRef& structsequenceref)
  {
    componentProperties.push_back(structsequenceref.clone());
  }

  const ossie::ComponentPropertyList& componentproperties_pimpl::
  post_componentproperties ()
  {
    return componentProperties;
  }

  // findcomponent_pimpl
  //

  void findcomponent_pimpl::
  pre ()
  {
    namingservicename = "";
  }

  void findcomponent_pimpl::
  componentresourcefactoryref ()
  {
  }

  void findcomponent_pimpl::
  namingservice (const ::std::string& namingservice)
  {
      namingservicename = namingservice;
  }

  ::std::string findcomponent_pimpl::
  post_findcomponent ()
  {
    LOG_TRACE(sad_parser, "post findcomponent: " << namingservicename)
    return namingservicename;
  }

  // componentresourcefactoryref_pimpl
  //

  void componentresourcefactoryref_pimpl::
  pre ()
  {
  }

  void componentresourcefactoryref_pimpl::
  resourcefactoryproperties ()
  {
  }

  void componentresourcefactoryref_pimpl::
  refid (const ::std::string& refid)
  {
    // TODO
    //
  }

  void componentresourcefactoryref_pimpl::
  post_componentresourcefactoryref ()
  {
  }

  // devicethatloadedthiscomponentref_pimpl
  //

  void devicethatloadedthiscomponentref_pimpl::
  pre ()
  {
      _refid = "";
  }

  void devicethatloadedthiscomponentref_pimpl::
  refid (const ::std::string& refid)
  {
      this->_refid = refid;
  }

  std::string devicethatloadedthiscomponentref_pimpl::
  post_devicethatloadedthiscomponentref ()
  {
      return _refid;
  }

  // deviceusedbythiscomponentref_pimpl
  //

  void deviceusedbythiscomponentref_pimpl::
  pre ()
  {
      info = std::pair<std::string, std::string>();
  }

  void deviceusedbythiscomponentref_pimpl::
  refid (const ::std::string& refid)
  {
      info.first = refid;
  }

  void deviceusedbythiscomponentref_pimpl::
  usesrefid (const ::std::string& usesrefid)
  {
      info.second = usesrefid;
  }

  std::pair<std::string, std::string> deviceusedbythiscomponentref_pimpl::
  post_deviceusedbythiscomponentref ()
  {
      return info;
  }

  // deviceusedbyapplication
  //

  void deviceusedbyapplication_pimpl::
  pre ()
  {
      usesRefId = "";
  }

  void deviceusedbyapplication_pimpl::
  usesrefid (const ::std::string& idIn)
  {
      usesRefId = idIn;
  }

  ::std::string deviceusedbyapplication_pimpl::
  post_deviceusedbyapplication ()
  {
      return usesRefId;
  }

  // resourcefactoryproperties_pimpl
  //

  void resourcefactoryproperties_pimpl::
  pre ()
  {
  }

  void resourcefactoryproperties_pimpl::
  simpleref (const ossie::SimplePropertyRef& simpleref)
  {
    // TODO
    //
  }

  void resourcefactoryproperties_pimpl::
  simplesequenceref (const ossie::SimpleSequencePropertyRef& simplesequenceref)
  {
    // TODO
    //
  }

  void resourcefactoryproperties_pimpl::
  structref (const ossie::StructPropertyRef& structref)
  {
    // TODO
    //
  }

  void resourcefactoryproperties_pimpl::
  structsequenceref (const ossie::StructSequencePropertyRef& structsequenceref)
  {
    // TODO
    //
  }

  void resourcefactoryproperties_pimpl::
  post_resourcefactoryproperties ()
  {
  }

  // simpleref_pimpl
  //

  void simpleref_pimpl::
  pre ()
  {
    simple = ossie::SimplePropertyRef();
  }

  void simpleref_pimpl::
  refid (const ::std::string& refid)
  {
    simple._id = refid;
  }

  void simpleref_pimpl::
  value (const ::std::string& value)
  {
    simple._value = value;
  }

  const ossie::SimplePropertyRef& simpleref_pimpl::
  post_simpleref ()
  {
    return simple;
  }

  // simplesequenceref_pimpl
  //

  void simplesequenceref_pimpl::
  pre ()
  {
    simpleseq._values.clear();
    simpleseq = ossie::SimpleSequencePropertyRef();
  }

  void simplesequenceref_pimpl::
  values (const ::std::vector<std::string>& values)
  {
      simpleseq._values = values;
  }

  void simplesequenceref_pimpl::
  refid (const ::std::string& refid)
  {
      simpleseq._id = refid;
  }

  const ossie::SimpleSequencePropertyRef& simplesequenceref_pimpl::
  post_simplesequenceref ()
  {
      return simpleseq;
  }

  // structref_pimpl
  //

  void structref_pimpl::
  pre ()
  {
    structref._values.clear();
    structref = ossie::StructPropertyRef();
  }

  void structref_pimpl::
  simpleref (const ossie::SimplePropertyRef& simpleref)
  {
    structref._values.insert(simpleref._id,std::auto_ptr<ossie::ComponentProperty>(simpleref.clone()) );
  }

  void structref_pimpl::
  simplesequenceref (const ossie::SimpleSequencePropertyRef& simplesequenceref)
  {
    structref._values.insert(simplesequenceref._id,std::auto_ptr<ossie::ComponentProperty>(simplesequenceref.clone()) );
  }

  void structref_pimpl::
  refid (const ::std::string& refid)
  {
    structref._id = refid;
  }

  const ossie::StructPropertyRef& structref_pimpl::
  post_structref ()
  {
      return structref;
  }

  // structsequenceref_pimpl
  //

  void structsequenceref_pimpl::
  pre ()
  {
    structsequenceref._values.clear();
    structsequenceref = ossie::StructSequencePropertyRef();
  }

  void structsequenceref_pimpl::
  structvalue (const ossie::ComponentPropertyMap& value)
  {
      structsequenceref._values.push_back(value);
  }

  void structsequenceref_pimpl::
  refid (const ::std::string& refid)
  {
      structsequenceref._id = refid;
  }

  const  ossie::StructSequencePropertyRef& structsequenceref_pimpl::
  post_structsequenceref ()
  {
    return structsequenceref;
  }

  // structvalue_pimpl
  //

  void structvalue_pimpl::
  pre ()
  {
      values.clear();
  }

  void structvalue_pimpl::
  simpleref (const ossie::SimplePropertyRef& simpleref)
  {
    values.insert(simpleref._id,std::auto_ptr<ossie::ComponentProperty>(simpleref.clone()) );
  }

  void structvalue_pimpl::
  simplesequenceref (const ossie::SimpleSequencePropertyRef& simplesequenceref)
  {
    values.insert(simplesequenceref._id,std::auto_ptr<ossie::ComponentProperty>(simplesequenceref.clone()) );
  }

  const ossie::ComponentPropertyMap& structvalue_pimpl::
  post_structvalue ()
  {
    return values;
  }

  // values_pimpl
  //

  void values_pimpl::
  pre ()
  {
      values.clear();
  }

  void values_pimpl::
  value (const ::std::string& value)
  {
      values.push_back(value);
  }

  ::std::vector<std::string> values_pimpl::
  post_values ()
  {
      return values;
  }

  // componentinstantiationref_pimpl
  //

  void componentinstantiationref_pimpl::
  pre ()
  {
      _refid = "";
  }

  void componentinstantiationref_pimpl::
  refid (const ::std::string& refid)
  {
      _refid = refid;
  }

  ::std::string componentinstantiationref_pimpl::
  post_componentinstantiationref ()
  {
      return _refid;
  }

  // findby_pimpl
  //

  void findby_pimpl::
  pre ()
  {
      findby.reset(new ossie::FindBy());
  }

  void findby_pimpl::
  namingservice (const ::std::string& namingservice)
  {
      findby->findByNamingService = namingservice;
  }

  void findby_pimpl::
  stringifiedobjectref (const ::std::string& stringifiedobjectref)
  {
      findby->findByStringifiedObjectRef = stringifiedobjectref;
  }

  void findby_pimpl::
  domainfinder (const ::std::pair<std::string, std::string>& domainfinder)
  {
      findby->findByDomainFinderName = domainfinder.first;
      findby->findByDomainFinderType = domainfinder.second;
  }

  ::ossie::FindBy findby_pimpl::
  post_findby ()
  {
    return *findby;
  }

  // namingservice_pimpl
  //

  void namingservice_pimpl::
  pre ()
  {
    _name = "";
  }

  void namingservice_pimpl::
  name (const ::std::string& name)
  {
    this->_name = name;
  }

  ::std::string namingservice_pimpl::
  post_namingservice ()
  {
    return _name;
  }

  // domainfinder_pimpl
  //

  void domainfinder_pimpl::
  pre ()
  {
      domainfinder = std::pair<std::string, std::string>();
  }

  void domainfinder_pimpl::
  type (const ::std::string& type)
  {
      domainfinder.second = type;
  }

  void domainfinder_pimpl::
  name (const ::std::string& name)
  {
      domainfinder.first = name;
  }

  ::std::pair<std::string, std::string> domainfinder_pimpl::
  post_domainfinder ()
  {
    return domainfinder;
  }

  // hostcollocation_pimpl
  //

  void hostcollocation_pimpl::
  pre ()
  {
    hostcollocation.reset(new ossie::SoftwareAssembly::HostCollocation());
  }

  void hostcollocation_pimpl::
  componentplacement (const ::ossie::ComponentPlacement& componentplacement)
  {
    hostcollocation->placements.push_back(componentplacement);
  }

  void hostcollocation_pimpl::
  id (const ::std::string& id)
  {
    hostcollocation->id = id;
  }

  void hostcollocation_pimpl::
  name (const ::std::string& name)
  {
    hostcollocation->name = name;
  }

  ossie::SoftwareAssembly::HostCollocation hostcollocation_pimpl::
  post_hostcollocation ()
  {
      return *hostcollocation;
  }

  // assemblycontroller_pimpl
  //

  void assemblycontroller_pimpl::
  pre ()
  {
      _refid = "";
  }

  void assemblycontroller_pimpl::
  componentinstantiationref (const ::std::string& componentinstantiationref)
  {
      _refid = componentinstantiationref;
  }

  ::std::string assemblycontroller_pimpl::
  post_assemblycontroller ()
  {
      return _refid;
  }

  // connections_pimpl
  //

  void connections_pimpl::
  pre ()
  {
      connections.clear();
  }

  void connections_pimpl::
  connectinterface (const ::ossie::Connection& connectinterface)
  {
      connections.push_back(connectinterface);
      // Output ConnectionID
      if (strlen(connectinterface.getID()) == 0) {
          connections.back().connectionId = ossie::generateUUID();;
      }
      //if (strlen(connectinterface.getID()) == 0) {
      //std::ostringstream connname;
      //connname << "connection_" << (connections.size());
      //connections.back().connectionId = connname.str();
      //}
      LOG_TRACE(sad_parser, "added connection id " << connections.back().getID() << " type " << connections.back().getType());
  }

  ::std::vector<ossie::Connection> connections_pimpl::
  post_connections ()
  {
    return connections;
  }

  // connectinterface_pimpl
  //

  void connectinterface_pimpl::
  pre ()
  {
    connection.reset(new ossie::Connection());
  }

  void connectinterface_pimpl::
  usesport (const ::ossie::UsesPort& usesport)
  {
      connection->usesPort = usesport;
  }

  void connectinterface_pimpl::
  providesport (const ::ossie::ProvidesPort& providesport)
  {
      connection->providesPort = providesport;
      connection->type = ::ossie::Connection::PROVIDESPORT;
  }

  void connectinterface_pimpl::
  componentsupportedinterface (const ::ossie::ComponentSupportedInterface& componentsupportedinterface)
  {
      connection->componentSupportedInterface = componentsupportedinterface;
      connection->type = ::ossie::Connection::COMPONENTSUPPORTEDINTERFACE;
  }

  void connectinterface_pimpl::
  findby (const ::ossie::FindBy& findby)
  {
      connection->findBy = findby;
      connection->type = ::ossie::Connection::FINDBY;
  }

  void connectinterface_pimpl::
  id (const ::std::string& id)
  {
      LOG_TRACE(sad_parser, "connection id " << id);
      connection->connectionId = id;
  }

  ::ossie::Connection connectinterface_pimpl::
  post_connectinterface ()
  {
    return *connection;
  }

  // usesport_pimpl
  //

  void usesport_pimpl::
  pre ()
  {
      usesPort.reset(new ossie::UsesPort());
  }

  void usesport_pimpl::
  usesidentifier (const ::std::string& usesidentifier)
  {
      usesPort->identifier = usesidentifier;
  }

  void usesport_pimpl::
  componentinstantiationref (const ::std::string& componentinstantiationref)
  {
      usesPort->setComponentInstantiationRef(componentinstantiationref);
  }

  void usesport_pimpl::
  devicethatloadedthiscomponentref (const std::string& devicethatloadedthiscomponentref)
  {
      usesPort->setDeviceThatLoadedThisComponentRef(devicethatloadedthiscomponentref);
  }

  void usesport_pimpl::
  deviceusedbythiscomponentref (const ::std::pair<std::string, std::string>& ref)
  {
      usesPort->setDeviceUsedByThisComponentRef(ref.first, ref.second);
  }

  void usesport_pimpl::
  deviceusedbyapplication (const ::std::string& id)
  {
      usesPort->setDeviceUsedByApplication(id);
  }

  void usesport_pimpl::
  findby (const ::ossie::FindBy& findby)
  {
      usesPort->setFindBy(findby);
  }

  ::ossie::UsesPort usesport_pimpl::
  post_usesport ()
  {
    return *usesPort;
  }

  // providesport_pimpl
  //

  void providesport_pimpl::
  pre ()
  {
      provPort.reset(new ossie::ProvidesPort());
  }

  void providesport_pimpl::
  providesidentifier (const ::std::string& providesidentifier)
  {
      provPort->identifier = providesidentifier;
  }

  void providesport_pimpl::
  componentinstantiationref (const ::std::string& componentinstantiationref)
  {
      provPort->setComponentInstantiationRef(componentinstantiationref);
  }

  void providesport_pimpl::
  devicethatloadedthiscomponentref (const std::string& devicethatloadedthiscomponentref)
  {
      provPort->setDeviceThatLoadedThisComponentRef(devicethatloadedthiscomponentref);
  }

  void providesport_pimpl::
  deviceusedbythiscomponentref (const ::std::pair<std::string, std::string>& ref)
  {
      provPort->setDeviceUsedByThisComponentRef(ref.first, ref.second);
  }

  void providesport_pimpl::
  deviceusedbyapplication (const ::std::string& id)
  {
      provPort->setDeviceUsedByApplication(id);
  }

  void providesport_pimpl::
  findby (const ::ossie::FindBy& findby)
  {
      provPort->setFindBy(findby);
  }

  ::ossie::ProvidesPort providesport_pimpl::
  post_providesport ()
  {
    return *provPort;
  }

  // componentsupportedinterface_pimpl
  //

  void componentsupportedinterface_pimpl::
  pre ()
  {
      ciface.reset(new ossie::ComponentSupportedInterface());
  }

  void componentsupportedinterface_pimpl::
  supportedidentifier (const ::std::string& supportedidentifier)
  {
      ciface->identifier = supportedidentifier;
  }

  void componentsupportedinterface_pimpl::
  componentinstantiationref (const ::std::string& componentinstantiationref)
  {
      ciface->setComponentInstantiationRef(componentinstantiationref);
  }

  void componentsupportedinterface_pimpl::
  devicethatloadedthiscomponentref (const ::std::string& devicethatloadedthiscomponentref)
  {
      ciface->setDeviceThatLoadedThisComponentRef(devicethatloadedthiscomponentref);
  }

  void componentsupportedinterface_pimpl::
  deviceusedbythiscomponentref (const ::std::pair<std::string, std::string>& ref)
  {
      ciface->setDeviceUsedByThisComponentRef(ref.first, ref.second);
  }

  void componentsupportedinterface_pimpl::
  deviceusedbyapplication (const ::std::string& id)
  {
      ciface->setDeviceUsedByApplication(id);
  }

  void componentsupportedinterface_pimpl::
  findby (const ::ossie::FindBy& findby)
  {
      ciface->setFindBy(findby);
  }

  ::ossie::ComponentSupportedInterface componentsupportedinterface_pimpl::
  post_componentsupportedinterface ()
  {
    return *ciface;
  }

  // externalports_pimpl
  //

  void externalports_pimpl::
  pre ()
  {
      extPorts.clear();
  }

  void externalports_pimpl::
  port (const ossie::SoftwareAssembly::Port& port)
  {
      extPorts.push_back(port);
  }

  ::std::vector<ossie::SoftwareAssembly::Port> externalports_pimpl::
  post_externalports ()
  {
      return extPorts;
  }

  // port_pimpl
  //

  void port_pimpl::
  pre ()
  {
      port.reset(new ossie::SoftwareAssembly::Port());
  }

  void port_pimpl::
  externalname(const ::std::string& externalname)
  {
      port->externalname = externalname;
  }

  void port_pimpl::
  description (const ::std::string& description)
  {
    // TODO
    //
  }

  void port_pimpl::
  usesidentifier (const ::std::string& usesidentifier)
  {
      port->type = ossie::SoftwareAssembly::Port::USESIDENTIFIER;
      port->identifier = usesidentifier;
  }

  void port_pimpl::
  providesidentifier (const ::std::string& providesidentifier)
  {
      port->type = ossie::SoftwareAssembly::Port::PROVIDESIDENTIFIER;
      port->identifier = providesidentifier;
  }

  void port_pimpl::
  supportedidentifier (const ::std::string& supportedidentifier)
  {
      port->type = ossie::SoftwareAssembly::Port::SUPPORTEDIDENTIFIER;
      port->identifier = supportedidentifier;
  }

  void port_pimpl::
  componentinstantiationref (const ::std::string& componentinstantiationref)
  {
      port->componentrefid = componentinstantiationref;
  }

  ::ossie::SoftwareAssembly::Port port_pimpl::
  post_port ()
  {
      return *port;
  }

  // externalproperties_pimpl
  //

  void externalproperties_pimpl::
  pre ()
  {
      extProps.clear();
  }

  void externalproperties_pimpl::
  property (const ossie::SoftwareAssembly::Property& prop)
  {
      extProps.push_back(prop);
  }

  ::std::vector<ossie::SoftwareAssembly::Property> externalproperties_pimpl::
   post_externalproperties ()
  {
      return extProps;
  }

  // property_pimpl
  //

  void property_pimpl::
  pre ()
  {
      property.reset(new ossie::SoftwareAssembly::Property());
  }

  void property_pimpl::
  comprefid (const ::std::string& comprefid)
  {
      property->comprefid = comprefid;
  }

  void property_pimpl::
  propid (const ::std::string& propid)
  {
      property->propid = propid;
  }

  void property_pimpl::
  externalpropid (const ::std::string& externalpropid)
  {
      property->externalpropid = externalpropid;
  }

  ::ossie::SoftwareAssembly::Property property_pimpl::
   post_property ()
  {
      return *property;
  }

  // usesdevicedependencies_pimpl
  //

  void usesdevicedependencies_pimpl::
  pre ()
  {
      usesDevices.clear();
  }

  void usesdevicedependencies_pimpl::
  usesdevice (const ossie::SoftwareAssembly::UsesDevice& use)
  {
      usesDevices.push_back(use);
  }

  ::std::vector<ossie::SoftwareAssembly::UsesDevice> usesdevicedependencies_pimpl::
   post_usesdevicedependencies ()
  {
      return usesDevices;
  }

  // usesdevice_pimpl
  //

  void usesdevice_pimpl::
  pre ()
  {
      uses.reset(new ossie::SoftwareAssembly::UsesDevice());
  }

  void usesdevice_pimpl::
  propertyref (const ossie::PropertyRef& propRef)
  {
      uses->dependencies.push_back(propRef);
  }

  void usesdevice_pimpl::
  simpleref (const ossie::SimplePropertyRef& propRef)
  {
    uses->dependencies.push_back(propRef.clone());
  }

  void usesdevice_pimpl::
  simplesequenceref (const ossie::SimpleSequencePropertyRef& propRef)
  {
      uses->dependencies.push_back(propRef.clone());
  }

  void usesdevice_pimpl::
  structref (const ossie::StructPropertyRef& propRef)
  {
      uses->dependencies.push_back(propRef.clone());
  }

  void usesdevice_pimpl::
  structsequenceref (const ossie::StructSequencePropertyRef& propRef)
  {
      uses->dependencies.push_back(propRef.clone());
  }

  void usesdevice_pimpl::
  id (const ::std::string& id)
  {
      uses->id = id;
  }

  void usesdevice_pimpl::
  type (const ::std::string& type)
  {
      uses->type = type;
  }

  ossie::SoftwareAssembly::UsesDevice usesdevice_pimpl::
  post_usesdevice ()
  {
      return *uses;
  }

  // property_pimpl
  //

  void propertyref_pimpl::
  pre ()
  {
      propRef.reset(new ossie::SimplePropertyRef());
  }

  void propertyref_pimpl::
  refid (const ::std::string& refid)
  {
      propRef->_id = refid;
  }

  void propertyref_pimpl::
  value (const ::std::string& value)
  {
      propRef->_value = value;
  }

  ossie::PropertyRef propertyref_pimpl::
  post_propertyref ()
  {
      return ossie::PropertyRef(propRef->clone());
  }
}

