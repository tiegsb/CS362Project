/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.Assert;
import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.
   
   public UrlValidatorTest(String testName) {
      super(testName);
   }

   class urlPart
   {
       public String url;  
       public boolean valid; 
       
       urlPart(String newUrl, boolean newValid){
    	   url = newUrl;
    	   valid = newValid;
       }
   };
   
   urlPart[] scheme = new urlPart[] {
		 new urlPart("", false),
		 new urlPart("http://", true),
		 new urlPart("http//", false),
		 new urlPart("http:://", false),
		 new urlPart("http:/", false),
		 new urlPart("http:///", false),
		 new urlPart("htp://", true),
		 new urlPart("ht1tp://", true),
		 new urlPart("1http://", false),
		 new urlPart("://", false),
		 new urlPart("ht.tp://", false),
		 new urlPart("ht:tp://", false),
		 new urlPart("ht/tp://", false),
		 new urlPart("ht!tp://", false),
		 new urlPart("ht?tp://", false)
   };
   
   urlPart[] authority = new urlPart[] {
		 new urlPart("www.google.com", true),
		 new urlPart("www.google.c123om", false),
		 new urlPart("abc.google.com", true),
		 new urlPart("01234567890.google.com", true),
		 new urlPart("www.0123456789.com", true),
		 new urlPart("w!@$ww.google.com", false),
		 new urlPart("www.go!@$ogle.com", false),
		 new urlPart("www.google.c!@$?om", false),
		 new urlPart("google.com", true),
		 new urlPart("www.google", false),
		 new urlPart("", false),
		 new urlPart("74.125.224.72", true),
		 new urlPart("0.0.0.0", true),
		 new urlPart("255.255.255.255", true),
		 new urlPart("256.256.256.256", false),
		 new urlPart("-1.0.0.0", false)
   };
   
   urlPart[] port = new urlPart[] {
		 new urlPart("", true),
		 new urlPart(":80", true),
		 new urlPart(":0", true),
		 new urlPart(":65536", true),
		 new urlPart(":-1", false),
		 new urlPart(":65537", false),
		 new urlPart(":10000", true),
		 new urlPart(":9999", true),
		 new urlPart(":999", true),
		 new urlPart(":99", true),
		 new urlPart(":1000", true),
		 new urlPart(":abc", false),
		 new urlPart(":!@$", false)		 
   };
   
   urlPart[] path = new urlPart[] {
		 new urlPart("", true),
		 new urlPart("/", true),
		 new urlPart("/path", true),
		 new urlPart("/path/", true),
		 new urlPart("/0123456789", true),
		 new urlPart("/!@$=", true),
		 new urlPart("\\path", false)
   };
   
   urlPart[] query = new urlPart[] {
		 new urlPart("", true),
		 new urlPart("?action=view", true)  
   };
   

   
   public void testManualTest()
   {
	   printTest("http://www.amazon.com", true);
	   printTest("http://www.amazon123.com", true);
	   printTest("http://www.amazon!@#.com", false);
	   printTest("http://www123.amazon.com", true);
	   printTest("http://www!@#.amazon.com", false);
	   printTest("http://www.amazon.com123", false);
	   printTest("http://www.amazon.com//", true);
	   printTest("http://amazon.com", true);
	   printTest("amazon.com", true);
	   printTest("http://www.ama.zon.com", true);
	   printTest("http://www.ama zon.com", false);
	   printTest("www.amazon.com", true);
	   printTest("http://www.amazon.com/", true);
	   printTest("HTTP://WWW.AMAZON.COM", true);
	   printTest("http:///www.amazon.com", false);
	   printTest("", false);
	   printTest("http://www.amazon.com/index.html", true);
	   printTest("http://www.amazon.com/index", true);
	   printTest("http://www..com/", false);
	   printTest("ftp://www.amazon.com", true);
	   printTest("http:://www.amazon.com", false);
	   printTest("http:///www.amazon.com", false);
	   printTest("h123ttp://www.amazon.com", true);
	   printTest("123http://www.amazon.com", false);
	   printTest("http://www.amazon.com/asd?=asd", true);
   }
   
   
   public void schemePartition()
   {
	   String url;
	   
	   for(int i = 0; i < scheme.length; i++){
		   url = scheme[i].url + "www.google.com";
		   printTest(url, scheme[i].valid);
	   }
   }
   
   public void authorityPartition()
   {
	   String url;
	   
	   for(int i = 0; i < authority.length; i++){
		   url = "http://" + authority[i].url;
		   printTest(url, authority[i].valid);
	   }
   }
   
   public void portPartition()
   {
	   String url;
	   
	   for(int i = 0; i < port.length; i++){
		   url = "http://www.google.com" + port[i].url;
		   printTest(url, port[i].valid);
	   }
   }
   
   public void pathPartition()
   {
	   String url;
	   
	   for(int i = 0; i < path.length; i++){
		   url = "http://www.google.com" + path[i].url;
		   printTest(url, path[i].valid);
	   }
   }
   
   public void queryPartition()
   {
	   String url;
	   
	   for(int i = 0; i < query.length; i++){
		   url = "http://www.google.com/path" + query[i].url;
		   printTest(url, query[i].valid);
	   }
   }
   
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   
	   //the following urls must work for partition tests to be valid
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.google.com/path"));
	   
	   schemePartition();
	   
	   authorityPartition();
	   
	   portPartition();
	   
	   pathPartition();
	   
	   queryPartition();
	   
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   
   public void printTest(String url, Boolean expected)
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   Boolean result = urlVal.isValid(url);
	   
	   try {
		   assertEquals(expected, result);
		   System.out.print("PASS");
	   }
	   catch(AssertionError e){
		   System.out.print("FAIL");
	   }
	   System.out.printf(" - Test URL: %s Expected: %s Result: %s\n",url, expected, result);
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
