/*
* CS 362_400 Fall15
* Project Part A
* 
* Group Members:
* Brian Lamere
* Susan Lee
* Erik Ratcliffe
*
*/


/***********************
* EXPLAIN TESTISVALID()
************************/

This function builds URLs from a predefined set of URL parts arrays and runs the 
resulting strings through an isValid() function. 
The URL parts are broken down like so:

ResultPair[] testUrlScheme      - protocols ("http://", "ftp://", etc.)
ResultPair[] testUrlAuthority   - domains & IPs ("google.com", "1.2.3.4.5", etc.)
ResultPair[] testUrlPort        - ports (":80", ":-1", etc.)
ResultPair[] testUrlPath        - paths ("/test1", "/../", etc.)
ResultPair[] testUrlPathOptions - path variations ("/../file", etc.)
ResultPair[] testUrlQuery       - query strings ("?foo", etc.)

Other bits:

Object[] testUrlParts
  Collects all of the above MINUS testUrlPathOptions (array of 5 arrays)

Object[] testUrlPartsOptions 
  Collects all of the above MINUS testUrlPath (also array of 5 arrays)

int[] testPartsIndex = { 0, 0, 0, 0, 0}
  Contains index values for the five parts that make up a URL, so  
  <scheme><authority><port><path><query> each have an index in this array. 
  The array is used to track which elements are pulled out of the ResultPair[] 
  arrays above to build the test URLs.


/****************************
 * TOTAL NUMBER OF URLS
 ****************************/
The number of substrings for each ResultPair[] array
(NOTE: these numbers include one string each that is empty: ""):

testUrlScheme      - 9
testUrlAuthority   - 19
testUrlPort        - 7
testUrlPath        - 10
testUrlPathOptions - 15
testUrlQuery       - 3

Total testUrlParts[] strings:
  9 x 19 x 7 x 10 x 3 = 35,910


Total testUrlPartsOptions[] strings:
  9 x 19 x 7 x 15 x 3 = 53,865

  
/***********************
* HOW IT'S BUILDING URLS
************************/
It’s iterating through each index for each result pair (testURLScheme, 
testUrlAuthority, testURLPort, testPath OR testUrlPathOptions, testUrlQuery) 
and creating complete URLs to test.  
 

/**********************
* EXAMPLE OF VALID URL
***********************/
So in the overloaded version of testIsValid(), if urlVal.isValid(url) returns true, 
it logs the valid url to the console (line 108 of UrlValidatorTest.java). One of 
those logged examples that for sure works in a browser is:

http://www.google.com:80

Note that this url will get built when both the testPath and testUrlQuery ResultPair[] 
object arrays are indexed to their respective “” empty string ResultPairs.


/************************
* EXAMPLE OF INVALID URL
*************************/
So, in order to get an invalid url, I just added the following code to the 
testIsValid(Object[] testObjects, long options) method @line 109:

	else
    	System.out.println(“INVALID__”+url);

Doing this identified a large number of invalid urls, one of which is:

://.1.2.3.4/test1/file?action=view


/******************************
* COMPARISON TO UNIT/CARD TESTS
*******************************/
Yes. Tests boundary cases. For instance, the testUrlPort ResultPair tests port 80, 
a known http port, as well as “:65636”, which is outside the range of the valid ports. 
Plus, it also tests port 0 (lowest port number) and port 65535 (max port number). Same 
for testUrlAuthority: it tests “www.google.com”, a known valid url, and it tests 
256.256.256.256, which is outside the range of valid IPv4 address. (Also it tests 
“1.2.3.4.5” which is not a valid IP address).

In terms of random testing, it makes sense with card game tests because the vast
combinations of options would be difficult to step through, but URLs have fewer 
pieces and each piece is either locked tight (schemes, ports) or loosey-goosey by 
design (host/domain names) so there are fewer mysteries when something breaks.

In terms of complexity, the testIsValid method itself does not require any complex 
inputs nor does it involve complex calculations between multiple objects or methods.  
The complexity comes from the logic to develop simple tests that could catch bugs in the code.  
