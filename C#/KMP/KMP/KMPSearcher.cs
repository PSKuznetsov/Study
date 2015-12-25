using System;

namespace KMP
{
	public class KMPSearcher
{
  private char[] pattern;   // The pattern to search for
  private int[]  prefixFunc; // The prefix function for search to skip ahead

	public KMPSearcher(char[] pattern) {

	    this.pattern = new char[pattern.Length];
	    Array.Copy(pattern, this.pattern, pattern.Length);

	    this.prefixFunc = BuildPrefixTable(pattern);           // use a helper to build prefixFunc
  }

  private int[] BuildPrefixTable(char[] pattern) {

    int[] result = new int[pattern.Length];
    int pos = 2;
    int cnd = 0;
    result[0] = -1;
    result[1] = 0;

     while (pos < pattern.Length) {

	      if (pattern[pos - 1] == pattern[cnd]) {

	        ++cnd; 
	        result[pos] = cnd; 
	        ++pos;
	      }
	      else if (cnd > 0)

	        cnd = result[cnd];

	      else {

	        result[pos] = 0; 
	        ++pos;
	      }
    }
    return result;
  }

  public int Search(char[] stringToSearch) {
    // look for pattern inside of string
    int m = 0;
    int i = 0;
		while (m + i < stringToSearch.Length) {
			if (this.pattern[i] == stringToSearch[m + i]) {
        		if (i == this.pattern.Length - 1)
          			return m;
        		++i;
      		}
      		else {
        		m = m + i - this.prefixFunc[i];
        		if (this.prefixFunc[i] > -1)
         			i = this.prefixFunc[i];
        		else
          			i = 0;
      		}
    	}

    return -1;  // not found
  }
}
}

