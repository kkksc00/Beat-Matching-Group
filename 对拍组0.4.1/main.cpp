// Please open with utf-8
// ===========请自行修改===========
#define Time_Limit 1 // 时间限制(单位: 秒)

// ===========以下请勿修改===========
#include<cstdio>
#include<cstring>

#include<utility>
#include<chrono>
#include<future>
using namespace std;

pair<int,int> ret;

pair<int,int> run(char file[],char command[],bool no_time_limit=1,int time_limit=Time_Limit)
{
	auto runner=[=](){return system(command);};
	if(no_time_limit)
		return make_pair(0,runner());
	future<int> checker=async(launch::async,[=](){return system(command);});
	auto status=checker.wait_for(chrono::seconds(time_limit));
	if(status==future_status::timeout)
	{
		char *temp=new char[1005];
		*temp='\0';
		strcat(temp,"taskkill /f /im ");
		strcat(temp,file);
		strcat(temp," > nul");
		system(temp);
		return make_pair(1,-1);
	}
	return make_pair(0,checker.get());
}

signed main()
{
	system("chcp 65001 > nul");
	
	puts("==================编译==================");
	
	puts("===正在编译 random.cpp===");
	ret=run("","g++.exe UserFile\\random.cpp -o JudgingFile\\random -I Include -O2 -std=c++14 > JudgingFile\\information.bin");
	if(ret.second&1)
	{
		puts("random.cpp 编译失败, 错误信息如下:");
		run("","type JudgingFile\\information.bin");
		puts("\n对拍结束.");
		return -1;
	}
	
	puts("=====正在编译 ans.cpp=====");
	ret=run("","g++.exe UserFile\\ans.cpp -o JudgingFile\\ans -O2 -std=c++14 > JudgingFile\\information.bin");
	if(ret.second)
	{
		puts("ans.cpp 编译失败, 错误信息如下:");
		run("","type JudgingFile\\information.bin");
		puts("\n对拍结束.");
		return -1;
	}
	
	puts("=====正在编译 std.cpp=====");
	ret=run("","g++.exe UserFile\\std.cpp -o JudgingFile\\std -O2 -std=c++14 > JudgingFile\\information.bin");
	if(ret.second)
	{
		puts("std.cpp 编译失败, 错误信息如下:");
		run("","type JudgingFile\\information.bin");
		puts("\n对拍结束.");
		return -1;
	}
	
	puts("===正在编译 checker.cpp===");
	ret=run("","g++.exe UserFile\\checker.cpp -o JudgingFile\\checker -O2 -std=c++14 > JudgingFile\\information.bin");
	if(ret.second)
	{
		puts("checker.cpp 编译失败, 错误信息如下:");
		run("","type JudgingFile\\information.bin");
		puts("\n对拍结束.");
		return -1;
	}
	
	puts("==================对拍==================");
	
	int sample=0;
	while(1)
	{
		printf("======第 %d 组数据======\n",++sample);
		
		ret=run("random.exe","JudgingFile\\random.exe > JudgingFile\\in.txt");
		if(ret.second)
		{
			printf("random.cpp(随机数据生成器) 返回值异常, 为 %d, 对拍结束.",ret.second);
			return -1;
		}
		
		ret=run("ans.exe","JudgingFile\\ans.exe < JudgingFile\\in.txt > JudgingFile\\ans_out.txt");
		if(ret.second)
		{
			printf("ans.cpp(暴力或正解) 返回值异常, 为 %d, 对拍结束.",ret.second);
			return -1;
		}
		
		ret=run("std.exe","JudgingFile\\std.exe < JudgingFile\\in.txt > JudgingFile\\std_out.txt 2> nul",0);
		if(ret.first)
		{
			printf("超过时间限制(Time Limit Exceed), 对拍结束.");
			run("","if exist Hack\\ans.txt del Hack\\ans.txt");
			run("","copy JudgingFile\\in.txt Hack > nul");
			run("","copy JudgingFile\\ans_out.txt Hack > nul");
			run("","ren Hack\\ans_out.txt ans.txt > nul");
			return -1;
		}
		if(ret.second)
		{
			printf("运行时错误(Runtime Error), 对拍结束.");
			run("","if exist Hack\\ans.txt del Hack\\ans.txt");
			run("","copy JudgingFile\\in.txt Hack > nul");
			run("","copy JudgingFile\\ans_out.txt Hack > nul");
			run("","ren Hack\\ans_out.txt ans.txt > nul");
			return 0;
		}
		
		ret=run("checker.exe","JudgingFile\\checker.exe");
		if(ret.second==0)
		{
			printf("答案错误(Wrong Answer), 对拍结束.");
			run("","if exist Hack\\ans.txt del Hack\\ans.txt");
			run("","copy JudgingFile\\in.txt Hack > nul");
			run("","copy JudgingFile\\ans_out.txt Hack > nul");
			run("","ren Hack\\ans_out.txt ans.txt > nul");
			return 0;
		}
		if(ret.second!=1)
		{
			printf("ans.cpp(输出检查器) 返回值异常, 为 %d, 对拍结束.",ret.second);
			return -1;
		}
		
		puts("答案正确(Accepted)");
	}
	return 0;
}