stack_classtemp.cc:
实现了栈的模板形式

template2.cc：实现了一个简单的函数模板的成员函数形式，使用typecast进行类型转化

template.cc:嵌套模板函数的模板类,利用这个模板类实现简单的类型转化,嵌套模板类的使用

object_member_template.cc:
类模板的定义可以放在另一个类中，实例化之后的模板对象可以作为另一个类的成员
类模板不等于类定义，需要实例化或者特化生成类实例


variadictemplate.cc：模板参数包和函数参数包的使用,模板包相当于迭代展开
因此，参数里面的第一个定义的display（）必须也要写上,或者不用模板也可以，只要能
展开第一个参数即可,解包过程如下
    display(10, 11.11, 'a', "hello");
        //  cout << 10 << endl;
        //  display(11.11, 'a', "hello");
        //      cout << 11.11 << endl;
        //      display('a', "hello");
        //          cout << 'a' << endl;
        //          display("hello");
        //              cout << "hello" << endl;
        //              display();
