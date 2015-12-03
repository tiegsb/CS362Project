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
		 new urlPart("https://", true),
		 new urlPart("http//", false),
		 new urlPart("http:://", false),
		 new urlPart("http:/", false),
		 new urlPart("http:///", false),
		 new urlPart("htp://", true),
		 new urlPart("ht1tp://", true),
		 new urlPart("1http://", false),
		 new urlPart("://", false),
		 new urlPart("ht.tp://", true),
		 new urlPart("ht+tp://", true),
		 new urlPart("ht-tp://", true),
		 new urlPart("ht:tp://", false),
		 new urlPart("ht/tp://", false),
		 new urlPart("ht!tp://", false),
		 new urlPart("ht?tp://", false)
   };
   
   urlPart[] authority = new urlPart[] {
		 new urlPart("www.google.com", true),
		 new urlPart("www.google.co.in", true),
		 new urlPart("www.google.net", true),
		 new urlPart("www.google.in", true),
		 new urlPart("www.google.uk", true),
		 new urlPart("www.google.co.uk", true),
		 new urlPart("www.oregonstate.edu", true),
		 new urlPart("cnas.ucr.edu", true),
		 new urlPart("www.google.org", true),
		 new urlPart("www.google.ac.uk", true),
		 new urlPart("www.usa.gov", true),
		 new urlPart("www.google.mil.in", true),
		 new urlPart("www.registry.gov.in", true),
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
		 new urlPart(":999", true),
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
		 new urlPart("/~path", true),
		 new urlPart("\\path", false)
   };
   
   urlPart[] query = new urlPart[] {
		 new urlPart("", true),
		 new urlPart("?action=view", true),
		 new urlPart("?123456890", true),
		 new urlPart("?!@$%^&*", true),
   };
   
   urlPart[] fragment = new urlPart[] {
		 new urlPart("", true),
		 new urlPart("#fragment", true),
		 new urlPart("#123456890", true), 
		 new urlPart("#!@$%^&*?", true)
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

		printTest("http://wwwtestdom.com", false); //bug, should be false
		printTest("ftp://www.testdom.com", true);
		printTest("ewlfjwef://www.testdom.com", false); //bug, should be false
		printTest("http://www.testdom.exe", true);//valid domain, should be true
		printTest("http://www.testdom.in", true);//valid domain, tests true
		printTest("http://www.testdom.uk", true);//valid domain
		printTest("http://www.testdom.co.uk", true);//valid domain
		printTest("https://web.engr.oregonstate.edu/~gunea/CS290/", true);// ? causes error
   }
   
   
   public void schemePartition()
   {
	   String url;
	   int failCount = 0;
	   int testCount = 0;

	   for(int i = 0; i < scheme.length; i++){
		   url = scheme[i].url + "www.google.com";
		   if(printTest(url, scheme[i].valid) == -1){
		   		failCount++;
		   }
		   testCount++;
	   }
	   System.out.println();
	   System.out.printf("Failed Schemes: %d/%d\n\n", failCount, testCount);
   }
   
   public void authorityPartition()
   {
	   String url;
	   int failCount = 0;
	   int testCount = 0;.

	   for(int i = 0; i < authority.length; i++){
		   url = "http://" + authority[i].url;
		   if(printTest(url, authority[i].valid) == -1){
		   		failCount++;
		   }
		   testCount++;
	   }
	   System.out.println();
	   System.out.printf("Failed Authorities: %d/%d\n\n", failCount, testCount);
   }
   
   public void portPartition()
   {
	   String url;
	   int failCount = 0;
	   int testCount = 0;

	   for(int i = 0; i < port.length; i++){
		   url = "http://www.google.com" + port[i].url;
		   if(printTest(url, port[i].valid) == -1){
		   		failCount++;
		   }
		   testCount++;
	   }
	   System.out.println();
	   System.out.printf("Failed Ports: %d/%d\n\n", failCount, testCount);
   }
   
   public void pathPartition()
   {
	   String url;
	   int failCount = 0;
	   int testCount = 0;

	   for(int i = 0; i < path.length; i++){
		   url = "http://www.google.com" + path[i].url;
		   if(printTest(url, path[i].valid) == -1){
		   		failCount++;
		   }
		   testCount++;
	   }
	   System.out.println();
	   System.out.printf("Failed Paths: %d/%d\n\n", failCount, testCount);
   }
   
   public void queryPartition()
   {
	   String url;
	   int failCount = 0;
	   int testCount = 0;

	   for(int i = 0; i < query.length; i++){
		   url = "http://www.google.com/path" + query[i].url;
		   if(printTest(url, query[i].valid) == -1){
		   		failCount++;
		   }
		   testCount++;
	   }
	   System.out.println();
	   System.out.printf("Failed Queries: %d/%d\n\n", failCount, testCount);
   }

   public void fragmentPartition()
   {
	   String url;
	   int failCount = 0;
	   int testCount = 0;

	   for(int i = 0; i < fragment.length; i++){
		   url = "http://www.google.com/path/" + fragment[i].url;
		   if(printTest(url, fragment[i].valid) == -1){
		   		failCount++;
		   }
		   testCount++;
	   }
	   System.out.println();
	   System.out.printf("Failed Fragments: %d/%d\n\n", failCount, testCount);
   }

   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //the following urls must work for partition tests to be valid
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.google.com/path"));
	   
	   //partition testing
	   schemePartition();
	   authorityPartition();
	   portPartition();
	   pathPartition();
	   queryPartition();
	   fragmentPartition();

	   //unit testing
	   testUnitTest();	   
   }
   
   public void testUnitTest()
   {
	   String url;
	   boolean expected;
	   int failCount = 0;
	   int testCount = 0;

	   for (int schemeIt = 0; schemeIt < scheme.length; schemeIt++){
		   for (int authIt = 0; authIt < authority.length; authIt++){
			   for (int portIt = 0; portIt < port.length; portIt++){
				   for (int pathIt = 0; pathIt < path.length; pathIt++){
					   for (int queryIt = 0; queryIt < query.length; queryIt++){
						   for (int fragIt = 0; fragIt < fragment.length; fragIt++){
						   	   //build url
							   url = scheme[schemeIt].url + authority[authIt].url + port[portIt].url + path[pathIt].url + query[queryIt].url + fragment[fragIt].url;
			
							   //calculate expected outcome of url
							   expected = scheme[schemeIt].valid & authority[authIt].valid & port[portIt].valid & path[pathIt].valid & query[queryIt].valid & fragment[fragIt].valid;
							   
							   //run test
							   if(printTest(url, expected) == -1){
							   		failCount++;
							   }
							   testCount++;
						   }
					   }
				   }  
			   } 
		   }
	   }

	   System.out.println();
	   System.out.printf("Failed Tests: %d/%d\n\n", failCount, testCount);
   }
   
   public int printTest(String url, Boolean expected)
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   Boolean result = urlVal.isValid(url);
	   
	   try {
		   assertEquals(expected, result);
		   System.out.printf("PASS - Test URL: %s Expected: %s Result: %s\n",url, expected, result);
	   }
	   catch(AssertionError e){
		   System.out.printf("FAIL - Test URL: %s Expected: %s Result: %s\n",url, expected, result);
		   return -1;
	   }

	   return 0;
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
