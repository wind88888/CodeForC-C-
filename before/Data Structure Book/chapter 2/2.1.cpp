#include <iostream>

int main()
{
    char ch;
    int num, value=0;
    int flag = 0;//标志位，确定最后输出结果还是错误信息

    std::cin >> value;

    while(std::cin >> ch && ch != '=')
    {
        std::cin >> num;

        if (ch == '+')
            value += num;
        else if (ch == '-')
            value -= num;
        else if (ch == '*')
            value *= num;
        else if(ch == '/'){
            if (num == 0)
                flag = 1;
            else
                value /= num;   
        } 
        else 
            flag = 1;
    }

    if (flag == 0){
        std::cout << value << std::endl;
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }
    

    system("pause");
    return 0;
}