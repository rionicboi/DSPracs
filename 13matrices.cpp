/*
 *Write a program to implement: 
 * (i) Diagonal Matrix using one-dimensional array. 
 * (ii) Lower Triangular Matrix using one-dimensional array 
 * (iii) Upper Triangular Matrix using one-dimensional array 
 * (iv) Symmetric Matrix using one-dimensional array.
 */

#include<iostream>

using namespace std;

class matrix{
public:
    int *arr;
    int rows;
    int columns;
    int size;

    matrix(){
	rows = 3;
	columns = 3;
	size = rows*columns;
	arr = new int[size];
    }
    matrix(int r,int c){
	rows = r;
	columns = c;
	size = rows*columns;
	arr = new int[size];
    }

    virtual void input(){
	for(int i=0;i<rows;i++){
	    for(int j=0;j<columns;j++){
		cout << "Enter element of row " << i+1 << " column " << j+1 << " : " ;
		cin >> arr[(i*rows)+j];
	    }
	}
    }

    virtual void input(int e,int r,int c){
	if(r>rows)
	    cout << "Given row is > row in matrix" << endl;
	else if(c>columns)
	    cout << "Given columns is > columns in matrix" << endl;
	else
	    arr[(r-1)*rows + (c-1)] = e;
    }

    virtual int elAt(int r, int c){
	if(r>rows)
	    throw "Given row is > row in matrix";
	else if(c>columns)
	    throw "Given columns is > columns in matrix";
	else
	    return arr[(r-1)*rows + (c-1)];
    }

    virtual void display(){
	for(int i=0;i<rows;i++){
	    cout << endl;
	    for(int j=0;j<columns;j++){
		cout << arr[(i*rows)+j] << " ";
	    }
	}
	cout << endl;
    }
    //void delEl(int el){
	//if(r>rows)
	    //throw "Given row is > row in matrix";
	//else if(c>columns)
	    //throw "Given columns is > columns in matrix";
	//else
	    
    //}
    //void delEl(int r, int c);

};

class diagMat : public matrix{
public:
    int *arr;
    int rows;
    int columns;
    int size;
    diagMat(){
	rows = columns = 3;
	size = rows*columns;
	arr = new int[size];
    }
    diagMat(int r,int c){
	rows = r;
	columns = c;
	size = rows*columns;
	arr = new int[size];
    }

    void input(){
	int g = rows < columns ? rows : columns;
	for(int i=0;i<g;i++){
	    cout << "Enter diagonal element " << i+1 << "," << i+1 << " : ";
	    cin >> arr[i];
	}
    }

    void input(int el,int r, int c){
	if(r>rows)
	    cout << "Given row is > row in matrix" << endl;
	else if(c>columns)
	    cout << "Given columns is > columns in matrix" << endl;
	else if(r!=c)
	    cout << "You cant edit non diagonal elements" << endl;
	else
	    arr[r-1] = el;
    }

    int elAt(int r, int c){
	if(r>rows)
	    throw "Given row is > row in matrix";
	else if(c>columns)
	    throw "Given columns is > columns in matrix";
	else if(r==c)
	    return arr[r-1];
	else
	    return 0;
    }

    void display(){
	for(int i=0;i<rows;i++){
	    cout << endl;
	    for(int j=0;j<columns;j++){
		if(i==j)
		    cout << arr[i] << " ";
		else
		    cout << "0 ";
	    }
	}
	cout << endl;
    }

};

class lTriag : public matrix{
public:
    int *arr;
    int rows;
    int columns;
    int size;
    lTriag(){
	rows = columns = 3;
	size = rows*(rows+1)/2;
	arr = new int[size];
    }
    lTriag(int r,int c){
	if(r!=c){
	    cout << "no. of rows != coulumns.. need square Matrix.. defaulting to r=c=3" << endl;
	    r = c = 3;
	}
	rows = r;
	columns = c;
	size = rows*(rows+1)/2;
	arr = new int[size];
    }

    void input(){
	int x=0;
	for(int i=0;i<rows;i++){
	    for(int j=0;j<=i;j++){
		cout << "Enter lower Triag element "<< i+1 << "," << j+1 << " : ";
		cin >> arr[x++];
	    }
	}
    }

    void input(int el,int r, int c){
	if(r>rows)
	    cout << "Given row is > row in matrix" << endl;
	else if(c>columns)
	    cout << "Given columns is > columns in matrix" << endl;
	else if(c>r)
	    cout << "You cant edit elements which are not in lower triangle(columns<=rows)" << endl;
	else
	    arr[((r-1)*r/2)+c-1] = el;
    }

    int elAt(int r, int c){
	if(r>rows)
	    throw "Given row is > row in matrix";
	else if(c>columns)
	    throw "Given columns is > columns in matrix";
	else if(r>=c)
	    return arr[((r-1)*r/2)+c-1];
	else
	    return 0;
    }

    void display(){
	for(int i=0;i<rows;i++){
	    cout << endl;
	    for(int j=0;j<columns;j++){
		if(i>=j)
		    cout << arr[((i+1)*i/2)+j] << " ";
		else
		    cout << "0 ";
	    }
	}
	cout << endl;
    }

};

class uTriag : public matrix{
public:
    int *arr;
    int rows;
    int columns;
    int size;
    uTriag(){
	rows = columns = 3;
	size = rows*(rows+1)/2;
	arr = new int[size];
    }

    uTriag(int r,int c){
	if(r!=c){
	    cout << "no. of rows != coulumns.. need square Matrix.. defaulting to r=c=3" << endl;
	    r = c = 3;
	}
	rows = r;
	columns = c;
	size = rows*(rows+1)/2;
	arr = new int[size];
    }

    void input(){
	int x=0;
	for(int i=0;i<rows;i++){
	    for(int j=i;j<columns;j++){
		cout << "Enter lower Triag element "<< i+1 << "," << j+1 << " : ";
		cin >> arr[x++];
	    }
	}
    }

    void input(int el,int r, int c){
	if(r>rows)
	    cout << "Given row is > row in matrix" << endl;
	else if(c>columns)
	    cout << "Given columns is > columns in matrix" << endl;
	else if(c<r)
	    cout << "You cant edit elements which are not in upper triangle(columns>=rows)" << endl;
	else
	    arr[(r-1)*rows + c-1 - (r*(r-1)/2)] = el;
    }

    int elAt(int r, int c){
	if(r>rows)
	    throw "Given row is > row in matrix";
	else if(c>columns)
	    throw "Given columns is > columns in matrix";
	else if(r<=c)
	    return arr[(r-1)*rows + c-1 - (r*(r-1)/2)];
	else
	    return 0;
    }

    void display(){
	for(int i=0;i<rows;i++){
	    cout << endl;
	    for(int j=0;j<columns;j++){
		if(i<=j)
		    cout << arr[i*rows + j - (i*(i+1)/2)] << " ";
		else
		    cout << "0 ";
	    }
	}
	cout << endl;
    }


};

class symMat : public matrix{
public:
    int *arr;
    int rows;
    int columns;
    int size;

    symMat(){
	rows = columns = 3;
	size = rows*(rows+1)/2;
	arr = new int[size];
    }

    symMat(int r,int c){
	if(r!=c){
	    cout << "no. of rows != coulumns.. need square Matrix.. defaulting to r=c=3" << endl;
	    lTriag();
	}
	else{
	    rows = r;
	    columns = c;
	    size = rows*(rows+1)/2;
	    arr = new int[size];
	}
    }

    void input(){
	int x=0;
	for(int i=0;i<rows;i++){
	    for(int j=0;j<=i;j++){
		cout << "Enter element "<< i+1 << "," << j+1 << " : ";
		cin >> arr[x++];
	    }
	}
    }

    void input(int el,int r, int c){
	if(r>rows)
	    cout << "Given row is > row in matrix" << endl;
	else if(c>columns)
	    cout << "Given columns is > columns in matrix" << endl;
	else if(c>r)
	    arr[((c-1)*c/2)+r-1] = el;
	else
	    arr[((r-1)*r/2)+c-1] = el;
    }

    int elAt(int r, int c){
	if(r>rows)
	    throw "Given row is > row in matrix";
	else if(c>columns)
	    throw "Given columns is > columns in matrix";
	else if(r>=c)
	    return arr[((r-1)*r/2)+c-1];
	else
	    return 0;
    }

    void display(){
	for(int i=0;i<rows;i++){
	    cout << endl;
	    for(int j=0;j<columns;j++){
		if(i>=j)
		    cout << arr[((i+1)*i/2)+j] << " ";
		else
		    cout << arr[((j+1)*j/2)+i] << " ";
	    }
	}
	cout << endl;
    }
};

int main(){

    int ch,r,c;
    int x,y,num;
    matrix *mat;
CHOOSE:
    cout << "Enter number of rows : ";
    cin >> r;
    cout << "Enter number of columns : ";
    cin >> c;
    cout << "\n\t-------Choose-------\n1.Diagonal Matrix\t2. lower Triangular Matrix\t3. upper Triangular\t4. symmterical Matrix\t0. Exit\n  :";
    cin >> ch;
    if(ch==1){
	mat = new diagMat(r,c);
    }
    else if(ch==2){
	mat = new lTriag(r,c);
    }
    else if(ch==3)
	mat = new uTriag(r,c);
    else if(ch==4)
	mat = new symMat(r,c);
    else{
	cout << "Exiting.." << endl;
	return 0;
    }
MENU:
    cout << "\n\t\t\t---Menu---\n\t1. Input (all)\t2. Input/Change one element\n\t3. Get Element\t4. Display\t5. Choose Matrix\t0. Exit\n\t : ";
    cin >> ch;
    if(ch==1){
	mat->input();
    }
    else if(ch==2){
	cout << "Enter row : ";
	cin >> x;
	cout << "Enter columns : ";
	cin >> y;
	cout << "Enter number :";
	cin >> num;
	mat->input(num,x,y);
    }
    else if(ch==3){
	cout << "Enter row : ";
	cin >> x;
	cout << "Enter columns : ";
	cin >> y;
	try{
	    num = mat->elAt(x,y);
	    cout << "Number at " << x << "," << y << " = " << num << endl;
	}
	catch(const char *ch){
	    cout << ch;
	    cout << endl;
	}
    }
    else if(ch==4){
	mat->display();
    }
    else if(ch==5){
	goto CHOOSE;
    }
    else{
	cout << "Exiting.." << endl;
	return 0;
    }
    goto MENU;
    return 0;
}
