#include <iostream>
using namespace std ;
int main()
{
    int a = 5 ;
    int* p = &a ;
    int** pp = &p ;

    cout << "&a = " <<  &a << endl ;
        // in ra địa chỉ của biến a

    cout << "&p = " << &p << endl ;
        // in ra địa chỉ ban đầu vốn có của con trỏ 'p'

    cout << "p = &a = " << p << endl  ;
        // in ra địa chỉ của con trỏ 'p' được gán với địa chỉ của 'p'

    cout << "*(p + 1) = " << *(p + 1) << endl ;
        // lấy giá trị của ô nhớ 'p+ 1'

    cout << "&*p = p = " << &*p << endl ;
        // giá trị của con tro 'p' cũng chính là địa chỉ của nó

    cout << "*&p = p = " << *&p << endl ;

    cout << "a = " << a << endl ;
        // in ra giá trị của biến a

    cout << "*p = a = " << *p << endl ;
        // lấy giá trị tại địa chỉ 'p'

    cout << "pp = &p = " << pp << endl ;
        // in ra địa chỉ của 'p' do địa chỉ của 'pp' đã được gán cho địa chỉ của 'p'

    cout << "*pp = " << *pp << endl ;
        // in ra địa chỉ của con trỏ 'pp'

    cout << "**pp = " << *(*pp) << endl ;
        // lấy giá trị của tại địa chỉ '*pp' đã được gán trước đó

    cout << "&*pp = &p = " << &*pp << endl ;

    cout << "*&pp = &p = " << *&pp << endl << endl << endl ;

    //--------------------



    int b[3] = {1, 2}  ;
    int* q = b ;
    int** qq = &p ;


    cout << "b = " <<  b << endl ;
        // mảng bản chất là một con trỏ .in ra địa chỉ của 'b'

    cout << "&b = b = " << &b << endl ;

    cout << "&q = " << &q << endl ;

    cout << "q = " << q << endl ;

    cout << "*b = " << *b << endl ;

    cout << "&b[1] = " << &b[1] << endl ;

    cout << "&q[1] = " << &q[1] << endl ;

    cout << "*(q + 1) = " << *(q + 1) << endl ;

    cout << "qq = " << qq << endl ;

    cout << "*qq = " << *qq << endl ;

    cout << "**qq = " << **qq << endl ;

    cout << "*(*qq + 1) = " << *(*qq + 1) << endl ;





    return 0 ;
}
