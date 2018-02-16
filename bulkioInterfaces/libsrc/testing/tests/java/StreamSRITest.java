/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK bulkioInterfaces.
 *
 * REDHAWK bulkioInterfaces is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK bulkioInterfaces is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import org.ossie.properties.AnyUtils;

@RunWith(JUnit4.class)
public class StreamSRITest
{
    @Test
    public void testCreate() {
        BULKIO.StreamSRI sri = bulkio.sri.utils.create();
        Assert.assertEquals("Stream ID mismatch", "defaultSRI", sri.streamID);
        Assert.assertEquals("Version mismatch", 1, sri.hversion);
	Assert.assertEquals("XUnits mismatch", BULKIO.UNITS_TIME.value, sri.xunits);
	Assert.assertEquals("XStart mismatch", 0.0, sri.xstart, 0);
        Assert.assertEquals("XDelta mismatch", 1.0, sri.xdelta, 0);
        Assert.assertEquals("YUnits mismatch", 0, sri.yunits);
        Assert.assertEquals("YStart mismatch", 0.0, sri.ystart, 0);
        Assert.assertEquals("YDelta mismatch", 0.0, sri.ydelta, 0);
        Assert.assertEquals("Subsize mismatch", 0, sri.subsize, 0);
        Assert.assertFalse("Blocking mismatch", sri.blocking);
        Assert.assertEquals("Keywords mismatch", 0, sri.keywords.length);

	sri = bulkio.sri.utils.create("NEW-STREAM-ID", 1e6, BULKIO.UNITS_FREQUENCY.value, false);
        Assert.assertEquals("Stream ID mismatch", "NEW-STREAM-ID", sri.streamID);
        Assert.assertEquals("XDelta mismatch", 1e-6, sri.xdelta, 0);
        Assert.assertEquals("XUnits mismatch", BULKIO.UNITS_FREQUENCY.value, sri.xunits);
        Assert.assertFalse("Blocking mismatch", sri.blocking);
    }


    @Test
    public void testCompare() {
	BULKIO.StreamSRI a_sri = bulkio.sri.utils.create();
	BULKIO.StreamSRI b_sri = bulkio.sri.utils.create();
	BULKIO.StreamSRI c_sri = bulkio.sri.utils.create("THIS_DOES_NOT_MATCH");

        Assert.assertTrue("bulkio.sri.utils.compare method - same.",  bulkio.sri.utils.compare(a_sri, b_sri));
        Assert.assertFalse("bulkio.sri.utils.compare method - different - StreamID .", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.hversion = 2;
	Assert.assertFalse("bulkio.sri.utils.compare method - different - hversion", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.xstart = 3;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - xstart",  bulkio.sri.utils.compare(a_sri, c_sri));

	c_sri = bulkio.sri.utils.create();
	c_sri.xdelta = 100.0;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - xdelta", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.xunits = 100;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - xunits", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.subsize = 100;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - subsize", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.ystart = 3;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - ystart",  bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.ydelta = 100.0;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - ydelta", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.yunits = 100;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - yunits", bulkio.sri.utils.compare(a_sri, c_sri));

        c_sri = bulkio.sri.utils.create();
        c_sri.mode = 100;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - mode", bulkio.sri.utils.compare(a_sri, c_sri));

        CF.DataType kv = new CF.DataType("key_one", AnyUtils.stringToAny("1","long"));
        CF.DataType kv2 = new CF.DataType("key_one",  AnyUtils.stringToAny("1","long"));
        a_sri.keywords = new CF.DataType[1];
        a_sri.keywords[0] = kv;
        c_sri = bulkio.sri.utils.create();
        c_sri.keywords = new CF.DataType[1];
        c_sri.keywords[0] = kv2;
	Assert.assertTrue("bulkio.sri.utils.compare method - same - keyword item",  bulkio.sri.utils.compare(a_sri, c_sri));

        kv2 = new CF.DataType("key_one", AnyUtils.stringToAny("100","long"));
        c_sri = bulkio.sri.utils.create();
        c_sri.keywords = new CF.DataType[1];
        c_sri.keywords[0] = kv2;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - keywords value mismatch",
                           bulkio.sri.utils.compare(a_sri, c_sri));
        
        kv2 = new CF.DataType("key_two", AnyUtils.stringToAny("100","long"));
        c_sri = bulkio.sri.utils.create();
        c_sri.keywords = new CF.DataType[1];
        c_sri.keywords[0] = kv2;
        Assert.assertFalse("bulkio.sri.utils.compare method - different - keywords name mismatch",
                           bulkio.sri.utils.compare(a_sri, c_sri));

    }
}
