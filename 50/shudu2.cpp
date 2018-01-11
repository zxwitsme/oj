#include<iostream>  
using namespace std;  
    
int sudoku[9][9]={
	{5,3,0,6,0,0,0,9,8},
	{0,7,0,1,9,5,0,0,0},
	{0,0,0,0,0,0,0,6,0},
	{8,0,0,4,0,0,7,0,0},
	{0,6,0,8,0,3,0,2,0},
	{0,0,3,0,0,1,0,0,6},
	{0,6,0,0,0,0,0,0,0},
	{0,0,0,4,1,9,0,8,0},
	{2,8,0,0,0,5,0,7,9},
};  
    
//判断填在空白位置的数字在行、列上是否符合要求  
bool Judge1(int x, int y, int n)  
{  
    int i;  
      
    for(i=0;i<9;i++)  
    {  
        //判断 列  
        if((sudoku[i][y]==n)&& (i!=x))  
            return false;  
        //判断 行  
        if((sudoku[x][i]==n)&& (i!=y))  
            return false;  
    }  
  
    return true;  
}  
    
//判断填在空白位置的数字在九宫格之内是否符合要求  
bool Judge2(int x, int y, int n)  
{  
    int xx,yy,i,j;  
    xx=x/3;  
    yy=y/3;  
    for(i=xx*3;i<xx*3+3;i++)  
        for(j=yy*3;j<yy*3+3;j++)  
            if(sudoku[i][j]==n)  
                if(i==x&& j==y)  
                    continue;  
                else  
                    return false;  
    return true;  
}  
    
//填充空白数组  
bool Fill(int m)  
{  
    int n,x,y;  
    x=m/9;  
    y=m%9;  
    if (m>=81)  
        return true;  
    if (sudoku[x][y]==0)  
    {  
        for(n=1;n<=9;n++)  
        {  
            sudoku[x][y]=n;  
            //if(Judge1(x,y,n)&&Judge2(x,y,n))  
            if(Judge1(x,y,n))  
                if(Fill(m+1))  
                    return true;  
            sudoku[x][y]=0;  
                                  
        }  
    }  
    else  
        return Fill(m+1);  
  
    return false;  
}  
    
int main()  
{  
    //输入初始数独  
    int i,j,k;  
    /*
    cout << "输入初始数独数据，空白用0代替" <<endl;  
    for(i=0;i<9;i++)  
                for(j=0;j<9;j++)  
                            cin>>sudoku[i][j];  
    */  
    /*for(i=0;i<9;i++) 
    { 
                for(j=0;j<9;j++) 
                            cout<< sudoku[i][j] << " "; 
                cout << endl; 
    }*/  
  
      
    if(Fill(0))//填充数独的空白位置完毕  
    {  
        for(i=0;i<9;i++)  
        {  
            for(j=0;j<9;j++)  
            {  
                cout<< sudoku[i][j] << " ";  
                if(!((j+1)%3))  
                    cout<< "| ";  
            }  
            cout<< endl;  
            if(!((i+1)%3))  
            {  
                for(k=0;k<12;k++)  
                    cout<<"__";  
                cout<< endl;  
            }  
        }  
  
    }  
    else  
        cout << "该数独无解，请注意游戏规则或检查原始数独是否有误" << endl;  
  
    return 0;  
}  
