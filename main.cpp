#include<iostream>
using namespace std;
template<class T>
class Array
{
   private:
    T *a;
    int Size;
    int length;
      void Swap(int *n,int *p)
    {
        int temp;
        temp=*n;
        *n=*p;
        *p=temp;
    }

   public:
    Array(int s=5)

    {
         length=0;
        Size=s;
        a=new T[Size];

    }
    ~Array()
    {
        delete []a;
    }

    void Display()
    {
        for(int i=0;i<length;i++)
            cout<<a[i]<<" ";

    }

    void add(int n)
    {
        if(Size==length)
        {


            cout<<endl<<"array full";
            return;
        }
       else
        {


            a[length]=n;
            cout<<endl<<"value added";
            length++;
    }}
    void Insert(int index,T val)
    {
        if(Size==length)
        {


            cout<<endl<<"array full";
            return;}

        else if (index>=0&& index<=length)
        {



            for(int i=length-1;i>=index;i--)
            a[i+1]=a[i];
        a[index]=val;
        length++;
        cout<<endl<<"value inserted"<<endl;
    }
    }
    T del(int index)
    {T x=0;
        if(index>=0 && index<length)
        {
            x=a[index];
            for(int i=index;i<length-1;i++)
            {
                a[i]=a[i+1];
            }
            length--;
            return x;
        }
        return 0;
    }



        int linear_search(int n)
    {
        for(int i=0;i<length;i++)
        {
            if(a[i]==n)
            {
                Swap(a+i,a);

                return i;
            }
        }
        return -1;
    }
    int Binary_search(int n)
    {
        int s=0;
        int e=length-1;
        int mid;
        while(s<=e)
        {


        mid=(s+e)/2;
        if(a[mid]==n)
            return mid;

        if(n>a[mid])
        {
            s=mid+1;
        }
        else
            e=mid-1;
        }
        return -1;
    }
    T Sum_rec(int i)
    {
        if(i<0)
            return 0;
        if(i<length)
            return Sum_rec(i-1)+a[i];


    }
    T Sum()
    {
        int i;
        T sum=0;
        for(i=0;i<length;i++)
            sum+=a[i];
        return sum;

    }
    T get(int index)
    {
        if(index>=0&&index<length)
            return a[index];
        return -1;

    }
    void Set(int index,T val)
    {
        if(index>=0&&index<length)
        {



            a[index]=val;
            cout<<endl<<"success"<<endl;


    }
    else
    {
        cout<<"Failed";
    }

    }
    T Max()
    {
        int mv=a[0],i;
        for(i=1;i<length;i++)
        {
            if(a[i]>mv)
                mv=a[i];
        }
        return mv;
    }
    T Min()
    {
        int mv=a[0],i;
        for(i=1;i<length;i++)
        {
            if(a[i]<mv)
                mv=a[i];
        }
        return mv;
    }
    int Length()
    {
        return length;
    }
    T avg()
    {
        int sum=0;
        for(int i=0;i<length;i++)
        {
            sum+=a[i];
        }
        return sum/(length-1);
    }
    void Reverse()
    {
        int i,j;
        for(i=0,j=length-1;i<j;i++,j--)
        {
            Swap(a+i,a+j);
        }
    }
    void leftshift()
    {
        a[0]=0;
        int i;
        for(i=0;i<length-1;i++)
        {
            a[i]=a[i+1];
        }
        static int j=0;
        j++;
        a[length-j]=0;

    }
        void leftRot()
    {
       int f=a[0];
       int i;
        for(i=0;i<length-1;i++)
        {
            a[i]=a[i+1];
        }
        a[i]=f;


    }
    void rightshift()
    {
        a[length-1]=0;
        int i;
        static int r=0;
        for(i=length-2;i>=0;i--)
        {
            a[i+1]=a[i];
        }

        a[r]=0;
        r++;


    }
    void rightRot()
    {
        int right=a[length-1],i;
        for(i=length-2;i>=0;i--)
        {
            a[i+1]=a[i];
        }
        a[0]=right;
    }
    void insert_inSorted(T x)
    {
        if(Size==length)
            return;


        int i=length-1;
        while(i>0&&x<a[i])
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=x;
        length++;

    }
    bool is_Sorted()

    {
        for(int i=0;i<length-1;i++)
        {
            if(a[i]>a[i+1])
                return false;
        }
        return true;
    }
    void leftNegative()
    {
        int i=0,j=length-1;
        while(i<j)
        {
            while(a[i]<0)
                    i++;
                while(a[j]>=0)
                        j--;
                if(i<j)
                Swap(a+i,a+j);
        }
    }
    Array *merge_sort(Array *a2)
    {
        Array *c1=new Array(sizeof(Array));
        c1->Size=Size+a2->Size;

        int i=0,j=0,k=0;
        while(i<length&&j<a2->length)
        {
            if(a[i]<a2->a[j])
                c1->a[k++]=a[i++];

            else
                c1->a[k++]=a2->a[j++];
        }
        for(;i<length;i++)
            c1->a[k++]=a[i];
        for(;j<a2->length;j++)
            c1->a[k++]=a2->a[j];
            c1->length=k;
        return c1;
    }

    Array *Set_union(Array *a2)
    {
        Array *c=new Array(sizeof(Array));
        c->Size=Size+a2->Size;
        int i=0,j=0,k=0;
        while(i<length&&j<a2->length)
        {
            if(a[i]<a2->a[j])
                c->a[k++]=a[i++];
            else if(a[i]==a2->a[j])
            {c->a[k++]=a[i++];
            j++;}
            else
                c->a[k++]=a2->a[j++];
        }
          for(;i<length;i++)
            c->a[k++]=a[i];
        for(;j<a2->length;j++)
            c->a[k++]=a2->a[j];
            c->length=k;

        return c;
    }

    Array *Set_intersection(Array *a2)
    {
        Array *c=new Array(sizeof(Array));
        c->Size=Size;
        int i=0,j=0,k=0;
        while(i<length&&j<a2->length)
        {
            if(a[i]<a2->a[j])
            {

                i++;
            }
            else if(a[i]==a2->a[j])
            {

                c->a[k++]=a[i++];

            j++;}
            else
            j++;
        }
        c->length=k;


        return c;
    }
      Array *Set_difference(Array *a2)
    {
        Array *c=new Array(sizeof(Array));
        c->Size=Size;
        int i=0,j=0,k=0;
        while(i<length&&j<a2->length)
        {
            if(a[i]<a2->a[j])
            {
                c->a[k++]=a[i++];
            }
            else if(a[i]==a2->a[j])
            {
                i++;
                j++;

                }
            else
            j++;
        }
        for(;i<length;i++)
        {

            c->a[k++]=a[i];
        }
        c->length=k;


        return c;
    }
     void New(int s)
    {
        Size=s;
        length=0;
    }
};
int main()
{

     int option1;
      int s;
      cout<<"enter size: ";
    cin>>s;
    Array<int>arr(s);

     int value,index;
     do{



                cout<<endl<<" Array operations"<<endl<<endl<<endl;
                    cout<<"0.  new array"<<endl;
                    cout<<"1.  Display"<<endl;
                    cout<<"2.  Add"<<endl;
                    cout<<"3.  Insert"<<endl;
                    cout<<"4.  Delete"<<endl;
                    cout<<"5.  Search"<<endl;
                    cout<<"6.  Get"<<endl;
                    cout<<"7.  Set"<<endl;
                    cout<<"8.  Maximum"<<endl;
                    cout<<"9.  Minimum"<<endl;
                    cout<<"10. length"<<endl;
                    cout<<"11. Average"<<endl;
                    cout<<"12. Reverse"<<endl;
                    cout<<"13. Left Shift"<<endl;
                    cout<<"14. Left Rotation"<<endl;
                    cout<<"15. Right Shift"<<endl;
                    cout<<"16. Right Rotation"<<endl;
                    cout<<"17. Check if Sorted"<<endl;
                    cout<<"18. Insert in Sorted"<<endl;
                    cout<<"19. Shift negative values to left"<<endl;
                    cout<<"20. Sum"<<endl;
                    cout<<"21. two array operations"<<endl;
                    cout<<"22. exit"<<endl;
                    cout<<" enter option: ";
     cin>>option1;

    switch(option1)

    {
                        case 0: cout<<endl<<"enter size: ";
                                cin>>s;
                                arr.New(s);
                                break;

                        case 1: arr.Display();
                                break;

                        case 2: cout<<endl<<"enter value: "<<endl;

                                cin>>value;
                                arr.add(value);
                                break;
                        case 3: cout<<endl<<"enter index and value"<<endl;

                                cin>>index>>value;
                                arr.Insert(index,value);
                                break;
                        case 4: cout<<"enter index of the value to be deleted"<<endl;
                                cin>>index;
                                cout<<"deleted value: "<<arr.del(index)<<endl;
                                break;
                        case 5: cout<<"enter the value to be searched"<<endl;
                                cin>>value;
                                index=arr.Binary_search(value);
                                if(index<0)cout<<endl<<"not found";
                                else
                                cout<<"value at index: "<<index<<endl;
                                break;
                        case 6: cout<<"enter index "<<endl;
                                cin>>index;

                                cout<<endl<<"value: "<<arr.get(index)<<endl;
                                break;
                        case 7: cout<<"enter index and value: "<<endl;
                                cin>>index>>value;
                                arr.Set(index,value);
                                break;
                        case 8: cout<<endl<<arr.Max()<<endl;
                                break;
                        case 9: cout<<arr.Min()<<endl;
                                break;
                        case 10: cout<<"length: "<<arr.Length();
                                break;
                        case 11: cout<<"average: "<<arr.avg();
                                break;
                        case 12: arr.Reverse();
                                 cout<<endl<<"array reversed"<<endl;
                                break;
                        case 13: arr.leftshift();
                                 cout<<endl;
                                break;
                        case 14: arr.leftRot();
                                 cout<<endl;
                                break;
                        case 15: arr.rightshift();
                                 cout<<endl;
                                break;
                        case 16: arr.rightRot();
                                 cout<<endl;
                                 break;
                        case 17: cout<<arr.is_Sorted();
                                 break;
                        case 18: cout<<endl<<"enter value: ";
                                 cin>>value;
                                 arr.insert_inSorted(value);
                                 break;
                        case 19: arr.leftNegative();
                                 cout<<endl<<"success"<<endl;
                                 break;
                        case 20: cout<<"sum: "<<arr.Sum()<<endl;
                                 break;
                        case 21:
                                 int s1;
                                 cout<<endl<<"enter size for 2nd array ";
                                 cin>>s1;
                                 Array <int>arr1(s1);
                                 int option2;
                                 do{
                                        cout<<endl<<endl;
                                 cout<<"0. Insert values for 2nd array"<<endl;
                                 cout<<"1. Display 2nd array"<<endl;
                                 cout<<"2. Add in 2nd array"<<endl;
                                 cout<<"3. Merge two sorted array"<<endl;
                                 cout<<"4. Union of sets"<<endl;
                                 cout<<"5. Intersection of sets"<<endl;
                                 cout<<"6. Set difference"<<endl;
                                 cout<<"7. Go back"<<endl;
                                 cout<<"enter option: ";

                                 cin>>option2;
                                 switch(option2)
                                 {
                                     case 0: cout<<endl<<"enter index and value"<<endl;

                                             cin>>index>>value;
                                             arr1.Insert(index,value);
                                             break;
                                     case 1: arr1.Display();
                                             break;

                                     case 2: cout<<endl<<"enter value: "<<endl;

                                             cin>>value;
                                             arr1.add(value);
                                             break;
                                     case 3: Array<int>*c;
                                             c=arr.merge_sort(&arr1);
                                             cout<<endl;
                                             c->Display();
                                             break;
                                     case 4: Array<int>*c1;
                                             c1=arr.Set_union(&arr1);
                                             cout<<endl;
                                             c1->Display();
                                             break;
                                     case 5: Array<int> *c2;
                                             c2=arr.Set_intersection(&arr1);
                                             cout<<endl;
                                             c2->Display();
                                             break;
                                     case 6: Array<int>*c3;
                                             c3=c3->Set_difference(&arr1);
                                             cout<<endl;
                                             c3->Display();
                                             break;
                                            }
                                            }while(option2<7);
                                            break;

                    }
                    }while(option1<22);

    }


