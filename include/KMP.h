#ifndef _KMP_H
#define _KMP_H
#include <string>
#include <iostream>

inline void getnext(const std::string &ptr, int nxt[])
{
    int j = 0;
    for(int i = 1; i < ptr.size(); i++){
        while(ptr[j] != ptr[i] && j > 0){
            j = nxt[j - 1];
        }
        if(ptr[i] == ptr[j]) j++;
        nxt[i] = j;
    }
}

inline void getnextval(const std::string &ptr, int nxt[], int nxtval[])
{
    nxtval[0] = nxt[0];
    for(int i = 1; i < ptr.size(); i++){
        if(ptr[i] == ptr[nxt[i - 1]]){
            nxtval[i] = nxtval[nxt[i - 1]];
        }else{
            nxtval[i] = nxt[i];
        }
    }
}

inline void kmp(const std::string& str, const std::string& ptr)
{
    int n = ptr.size();
    int nxt[n];
    nxt[0] = 0;
    getnext(ptr, nxt);
    int i = 0, j = 0;
	while(i < str.size()){
		if(str[i] == ptr[j]){
			i++, j++;
		}else{
			if(j > 0) j = nxt[j - 1];
			else if(j == 0) i++;
		}

		if(j == ptr.size()){
			std::cout << i - ptr.size() + 1 << '\n';
			j = nxt[j - 1];
		} 
	}

	for(i = 0; i < ptr.size(); i++){
		std::cout << nxt[i] << " ";
	}
}

#endif // !_KMP_H