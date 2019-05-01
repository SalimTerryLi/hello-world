#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

class Cell {
public:
	Cell(const char* con){
		strcpy(this->content,con);
	}
	~Cell(){}

	void show(){
		printf("%s",this->content);
	}
private:
	char content[128];
};

class Table {
public:
	Table(){row=0;col=0;}
	Table(int row,int col):row(row),col(col){
		int count=row*col;
		while(count--){cells.push_back(Cell("none"));}
	}

	void show(){
		if(this->row*this->col==0){
			printf("Empty Table\n");
		}

		vector<Cell>::iterator cell=cells.begin();
		for (int r=0;r<row;r++){
			for (int c=0;c<col;c++){
				if(c!=0){
					{printf("\t");}
				}
				cell->show();
				cell++;		// TODO
			}
			printf("\n");
		}
	}
	void set(int row,int col,char* value){
		cells.at((row-1)*this->col+col-1)=Cell(value);
	}
	int addRow(){
		if(this->col==0){
			this->col=1;
		}
		int count=this->col;
		while(count--){
			cells.push_back(Cell("none"));
		}
		this->row++;
		return 0;
	}
	void delRow(int n){
		cells.erase(cells.begin()+(n-1)*this->col,cells.begin()+n*this->col-1);
		this->row--;
		if(this->col==1){
			this->col=0;
		}
		return;
	}
	int addColumn(){
		if(this->row==0){
			this->row=1;
		}
		for(int r=this->row;r>=1;r--){
			cells.insert(cells.begin()+this->col*r-1,Cell("none"));
		}
		this->col++;
		return 0;
	}
	void delColumn(int n){
		for(int r=this->row;r>=1;r--){
			cells.erase(cells.begin()+this->col*(r-1)+n-1);
		}
		this->col--;
		if(this->row==1){
			this->row=0;
		}
		return;
	}
private:
	vector<Cell> cells;
	int row;
	int col;
};

int main() {
	Table tb;
	tb.show();
	printf("\n");
	tb.addRow();
	tb.show();
	printf("\n");
	tb.addColumn();
	tb.show();
	printf("\n");
	Table tb1(5,5);
	tb1.show();
	printf("\n");
	tb1.set(1,1,"30");
	tb1.set(2,2,"hello");
	tb1.show();
	printf("\n");
	tb1.delRow(1);
	tb1.show();
	printf("\n");
	tb1.delColumn(1);
	tb1.show();
	printf("\n");
	return 0;
}
