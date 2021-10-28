// 字符串展示

#include <iostream>
#include <cstring>



using namespace std;

int main(){

    char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
    char name[] = {"hahahahahah"};
    char tets[7];

    cout << site << endl;
    cout << name <<endl;


    string title;
    cout <<"输入title:"<<endl;
    cin>>title;
    cout << title <<endl;

    // 字符串赋值拼接操作

    // 复制char
    strcpy(tets,site);
    cout << tets <<endl;

    //获取长度
    int length = strlen(name);
    cout << length <<endl;

    int length2 = title.size();
    cout << length2 <<endl;

    //拼接
    cout << strcat(site,name) << endl;
    string id = "1234";
    string result = name + id;
    cout << result <<endl;


    system("pause");
    return 0;
}