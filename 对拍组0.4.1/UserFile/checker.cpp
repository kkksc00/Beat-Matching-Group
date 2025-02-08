#include<iostream>
#include<cstdlib>

#define finish fflush(stdin);std::cin.sync();
#define OPEN_IN finish;freopen("JudgingFile\\in.txt","r",stdin);
#define OPEN_ANS_OUT finish;freopen("JudgingFile\\ans_out.txt","r",stdin);
#define OPEN_STD_OUT finish;freopen("JudgingFile\\std_out.txt","r",stdin);

signed main()
{
	
	return system("fc JudgingFile\\ans_out.txt JudgingFile\\std_out.txt > nul")==0;
}