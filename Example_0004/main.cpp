/*************************************************************************************************************************
 * David Canino - canino.david@gmail.com
 *
 * Basic examples for the QT Library
 * Github: https://github.com/davidcanino/QT_examples.git
 *
 * This is the basic example for manipulating date and time in the current QT Library. No parameter is required.
 *
 * Last update: May 2016
 *************************************************************************************************************************/

#include<cstdlib>
#include<iostream>
#include <QVector>
#include <QTextStream>
using namespace std;

/* No parameter is required! */
int main(int argc,char **argv)
{
    QTextStream out(stdout);
    QVector<int> vals = {1, 2, 3, 4, 5};
    int pos;

    /* First, we check whether all is ok! */
    cout<<endl<<"\tEXAMPLE '"<<string(argv[0])<<"'"<<endl<<endl;
    if(argc!=1)
    {
        cout.flush();
        cerr<<"\tError: too much parameters"<<endl<<endl;
        cerr<<"\tUsage: "<<string(argv[0])<<endl<<endl;
        cerr.flush();
        return EXIT_FAILURE;
    }

    /*********************************************************************** TESTING QVector ****************************************************/

    out<<"\tThe current 'QVector'' is initialized"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tCapacity of the current 'QVector': "<<vals.capacity()<<endl;
    out<<"\tFirst value in the current 'QVector': "<<vals.first()<<endl;
    out<<"\tLast value in the current 'QVector': "<<vals.last()<<endl;
    out<<"\tValues in the current 'QVector': ";
    for(int i=0;i<vals.count();i++) out<<vals.at(i)<<" ";
    out<<endl;
    out<<"\tAppending new value to the current 'QVector' ... ";
    vals.append(6);
    out<<"ok"<<endl;
    out<<"\tPrepending new value to the current 'QVector' ... ";
    vals.prepend(0);
    out<<"ok"<<endl;
    out<<"\tValues in the current 'QVector': ";
    Q_FOREACH(int v,vals) { out<<v<<" "; }
    out<<endl;
    out<<"\tValues (in reverse order) in the current 'QVector': ";
    for(QVector<int>::reverse_iterator it=vals.rbegin();it!=vals.rend();it++) { out<<(*it)<<" "; }
    out<<endl<<endl;
    if(vals.isEmpty()) out<<"\tThe current 'QVector' is empty"<<endl;
    else out<<"\tThe current 'QVector' is not empty"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tAdding value 20 in position 7 to the current 'QVector' ... ";
    vals.insert(7,20);
    out<<"ok"<<endl;
    out<<"\tValue in position 7 in the current 'QVector': "<<vals.value(7)<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tValues in the current 'QVector': ";
    for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
    out<<endl<<endl;
    out<<"\tResizing the number of values in the current 'QVector' ... ";
    vals.resize(10);
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tAppending new values to the current 'QVector' ... ";
    vals<<11;
    vals<<12;
    vals<<13;
    vals<<14;
    out<<"ok"<<endl<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tValues in the current 'QVector': ";
    for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
    out<<endl<<endl;
    pos=vals.indexOf(20);
    if(pos!=-1)
    {
        out<<"\tValue 20 is stored in position "<<pos<<" in the current 'QVector'"<<endl;
        out<<"\tRemoving value "<<vals.takeAt(pos)<<" in position "<<pos<<" from the current 'QVector' ... ok"<<endl;
        out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
        out<<"\tValues in the current 'QVector': ";
        for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
        out<<endl;
    }
    else out<<"\tValue 20 is not stored"<<endl<<endl;
    out<<"\tRemoving the last value from the current 'QVector' ... ";
    vals.pop_back();
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl;
    out<<"\tRemoving the first value from the current 'QVector' ... ";
    vals.pop_front();
    out<<"ok"<<endl;
    out<<"\tNumber of values in the current 'QVector': "<<vals.size()<<endl<<endl;
    for(int k=vals.size()-1;k>5;k--)
    {
        out<<"\tRemoving value in position "<<k<<" from the current 'QVector' ... ";
        vals.erase(vals.begin()+k);
        out<<"ok. #Number of values in the current 'QVector': "<<vals.length()<<endl;
    }

    out<<"\tValues in the current 'QVector': ";
    for(QVector<int>::iterator it=vals.begin();it!=vals.end();it++) { out<<(*it)<<" "; }
    out<<endl;
    out<<"\tHashing value for the remaining values in the current 'QVector': "<<qHash(vals)<<endl<<endl;
    out<<"\tRemoving all values from the current 'QVector' ... ";
    vals.clear();
    out<<"ok. ";
    if(vals.empty()) out<<"The current 'QVector' is empty"<<endl<<endl;
    else out<<"The current 'QVector' is not empty"<<endl<<endl;
    out<<"\tPress the RETURN key to continue"<<endl;
    getchar();

    /************************************** END FOR TESTING 'QVector' **********************************************************/

    /* If we arrive here, we can deallocate everything! */
    vals.clear();
    return EXIT_SUCCESS;
}
