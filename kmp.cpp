int lps[MAX];

void computeLPS(string pat){
	int cur = 0;
	lps[0] = 0;
	int i = 1;

	while(i < pat.size()){
		if(pat[i] == pat[cur]){
			lps[i++] = ++cur;
		}	
		else{
			if(len){
				len = lps[len-1];
			}
			else{
				lps[i++] = 0;
			}
		}
	}

}

//all occurences of pat

int kmp(string text, string pat){
	int cnt = 0;
	computeLPS(pat);

	int i = 0, j = 0;  // index for txt[]
    while (i < text.size())
    {
		if (pat[j] == text[i])
		{
			j++;
			i++;
		}

		if (j == pat.size())
		{
			cnt++;
			j = lps[j-1];
		}

		// mismatch after j matches
		else if (i < text.size() && pat[j] != txt[i])
		{
		// Do not match lps[0..lps[j-1]] characters,
		// they will match anyway
			if (j != 0)
		 		j = lps[j-1];
			else
				 i = i+1;
		}
    }
    return cnt;

}