#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include <ncurses.h>
#include "display.h"
using namespace std;
//       !!!!!! 
//       Before the game starts use the function initialize()
void initialize()
{
	freopen("message_display.txt","w",stdout);
	printf("No messages or cautions!\n");
	fclose(stdout);
	return;
}
/*void in_put(string a)
{
	freopen("message_display.txt","w",stdout);
	cout<<a<<endl;
	fclose(stdout);
	return;
}*/ //if no conflicts
void in_put(string a)
{
    ofstream fout("message_display.txt");
    if (fout.is_open())
    {
        fout << a << endl;
        fout.close();
    }
    else
    {
    	return; 
        // Handle the error
    }
}
/*void newest_message()
{
	ifstream fin;
	fin.open("message_display.txt");
	int ls=1;
	string s[100001];
	while(fin>>s[ls])
	{
		ls++;
	}
	fin.close();
	freopen("CON","w",stdout);
	for(int i=1;i<=ls;i++)
	{
		cout<<s[i]<<" ";
	}
	return;
}*/// if no conflicts
void newest_message()
{
    ifstream fin("message_display.txt");
    int ls = 1;
    string s[100001];
    if (fin.is_open())
    {
        while (fin >> s[ls])
        {
            ls++;
        }
        fin.close();
    }
    else
    {
        return;
        // Handle the error
    }

    // Initialize the curses library
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    // Print the messages using the curses library
    for (int i = 1; i < ls; i++)
    {
        printw("%s ", s[i].c_str());
    }

    // Wait for a key press
    getch();

    // End the curses session
    endwin();
}

/* This to shou how to use functions
int main()
{
	initialize();
	int n;
	cin>>n;
	while(n)
	{
		if(n==1)
		{
			string x,mm;
			getline(cin,mm);
			getline(cin,x);
			in_put(x);
		}
		if(n==2)
		{
			newest_message();
		}
		cin>>n;
	}
} 
*/



//Unfinished advanced design
/*
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
//       !!!!!! 
//       Before the game starts use the function initialize()
void initialize()
{
	freopen("wordcount.txt","w",stdout);
	printf("0 0");
	fclose(stdout);
	freopen("message_display.txt","w",stdout);
	printf("No messages or cautions!\n");
	fclose(stdout);
	return;
}
void in_put(string a)
{
	int wordbegin,wordover;
	freopen("wordcount.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d%d",&wordbegin,&wordover);
	fclose(stdin);
	// collect the count of past newest message location
	string s[200010];
	int ls=1;
	for(int i=1;i<=10000;i++)
	{
		cout<<i<<endl;
		s[i]="$";
	}// initialization
	return;
	ifstream fin;
	fin.open("message_display.txt");
	fin.close();
	while(fin>>s[ls])
	{
		ls++;
	}
	// get the strings in messages
	for(int i=1;i<=ls;i++)
	{
		cout<<s[i]<<" ";
	}
	freopen("message_display.txt","w",stdout);
	for(int i=1;i<=ls;i++)
	{
		cout<<s[i]<<" ";
	}
	cout<<a<<endl;
	fclose(stdout);
	// obtain full sentences
	ls=1;
	for(int i=1;i<=10000;i++)
	{
		s[i]="$";
	}
	fin.open("message_display.txt");
	while(fin>>s[ls])
	{
		ls++;
	}
	fin.close();
	// calculate ls again
	freopen("wordcount.txt","w",stdout);
	printf("%d %d",wordover+1,ls);
	fclose(stdout);
	// save the count
	return;
}
void newest_message()
{
	int wordbegin,wordover;
	freopen("wordcount.txt","r",stdin);
	scanf("%d%d",&wordbegin,&wordover);
	fclose(stdin);
	string s[200001];
	int ls=1;
	for(int i=1;i<=10000;i++)
	{
		s[i]="$";
	}// initialization
	ifstream fin;
	fin.open("message_display.txt");
	while(fin>>s[ls])
	{
		ls++;
	}
	fin.close();
	freopen("ans.txt","w",stdout);
	for(int i=wordbegin;i<=wordover;i++)
	{
		cout<<s[i]<<" ";
	}
	return;
}
int main()
{
	initialize();
	int n;
	cin>>n;
	while(n)
	{
		if(n==1)
		{
			string x;
			cin>>x;
			in_put(x);
		}
		if(n==2)
		{
			newest_message();
		}
		cin>>n;
	}
} 
*/
