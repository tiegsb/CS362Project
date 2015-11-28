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

import org.junit.Assert;
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
		 new urlPart("https://", true)
		
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
   };
   
   urlPart[] port = new urlPart[] {
		 new urlPart("", true), 
   };
   
   urlPart[] path = new urlPart[] {
		 new urlPart("", true),
		 new urlPart("/", true),
		 new urlPart("/path", true),
		 new urlPart("/path/", true),
		 new urlPart("/0123456789", true),
		 new urlPart("/~path", true),
   };
   
   urlPart[] query = new urlPart[] {
		 new urlPart("", true),
		 new urlPart("?action=view", true)  
   };
   
   
   public void testManualTest()
   {
	   
	   
	   printTest("http://www.amazon.com", true);
	   
	   System.out.println();
	   printTest("http://wwwtestdom.com", false); //bug, should be false
	   
	   System.out.println();
	   printTest("ftp://www.testdom.com", true);
	   
	   System.out.println();
	   printTest("ewlfjwef://www.testdom.com", false); //bug, should be false
	   
	   System.out.println();
	   printTest("http://www.testdom.exe", true);//valid domain, should be true
	   
	   System.out.println();
	   printTest("http://www.testdom.in", true);//valid domain, tests true
	   
	   System.out.println();
	   printTest("http://www.testdom.uk", true);//valid domain
	   
	   System.out.println();
	   printTest("http://www.testdom.co.uk", true);//valid domain
	   
	   System.out.println();
	   printTest("https://web.engr.oregonstate.edu/~gunea/CS290/", true);// ? causes error
	   
	   System.out.println();
	   printTest("www.google.com", true);//valid
	   
	   
   }
   
   
 public void printTest(String url, boolean expected) {
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   
		   boolean result = urlVal.isValid(url);
		   
		   try {
			   assertEquals(expected, result);
			   System.out.print("PASS");
		   } 
		   catch(AssertionError e){
			   System.out.print("FAIL");
		   }
		   System.out.printf(" - Test URL: %s | Expected: %s | Result: %s\n",url, expected, result);
	}


public void countTest(String url, boolean expected, int failedtests[]) {
	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   boolean result = urlVal.isValid(url);
	   
	   try {
		   assertEquals(expected, result);
		   System.out.print("PASS");
	   } 
	   catch(AssertionError e){
		   System.out.print("FAIL");
		   failedtests[0] = failedtests[0] + 1;
	   }
	   System.out.printf(" - Test URL: %s | Expected: %s | Result: %s\n",url, expected, result);
}





public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println();
	   int numfailedschemes[] = {0};
	   int numfailedauths[] = {0};
	   for(int i = 0; i < scheme.length; i++){
		   String url;
		   for(int j =0; j < authority.length; j++)
		   {
			   url = scheme[i].url;
			   url = url + authority[j].url;
			   System.out.print("Testing Scheme:\n");
			   countTest(url, scheme[i].valid, numfailedschemes);
			   System.out.print("Testing Authority:\n");
			   countTest(url, authority[j].valid, numfailedauths);
			   System.out.println();
		   }	
	   }
	   System.out.printf("Failed Schemes: %d\n", numfailedschemes[0]);
	   System.out.printf("Failed Authorities: %d\n", numfailedauths[0]);
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
