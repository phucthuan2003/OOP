#include <bits/stdc++.h>

using namespace std;

class Items{
    private:
        string ID;
        int color;
        int quantity;
        double price;
    public:
        Items(){
            ID = "" ;
            color = 0 ;
            quantity = 0 ;
            price = 0 ;
        }
        Items(string ID , int color , int quantity , double price){
            this->ID = ID;
            this->color = color;
            this->quantity = quantity;
            this->price = price;
        }
        string getId(){
            return ID;
        }
        int getColor(){
            return color;
        }
        int getQuantity(){
            return quantity;
        }
        double getPrice(){
            return price;
        }
        void setId(string ID){
            this->ID = ID;
        }
        void setColor(int color){
            this->color = color;
        }
        void setQuantity(int quantity){
            this->quantity = quantity;
        }
        void setPrice(double price){
            this->price = price;
        }
        void readFromFile(ifstream &filein){
            filein >> ID;
            filein >> color;
            filein >> quantity;
            filein >> price;
        }
        void writeToFile(ofstream &fileout){
            fileout << "ID: " << ID << endl;
            fileout << "Color: " << color << endl;
            fileout << "Quantity: " << quantity << endl;
            fileout << "Price: " << price << endl; 
        }
};

class ItemsStore : public Items{
    private:
        string size;
    public:
        ItemsStore(string ID , int color , int quantity , double price , string size ) : Items(ID , color , quantity , price){
            this ->size = size;
        } 
        ItemsStore(){

        }
        string getSize(){
            return size;
        }
        void setSize(string size){
            this->size = size;
        }
        void readFromFile(ifstream &filein){
            Items::readFromFile(filein);
            if(filein.is_open()){
                string line;
                while(getline(filein , line )){
                    if(line.find("Size: ") != string::npos){
                        size = line.substr(line.find("Size: ") + 6 );
                        break;
                    }
                }
            }
            else {
                cout << "Cannot open file input.txt" << endl;
            }
        }
        void writeToFile(ofstream &fileout){
            Items::writeToFile(fileout);
            if(fileout.is_open()){
                fileout << "Size: " << size << endl;
            }
            else {
                cout << "Cannot open file output.txt" << endl;
            }
        }
};
class ListItemsStore : public ItemsStore{
    private:
        vector <ItemsStore> List;
    public: 
        void Add_List(ItemsStore add){
            List.push_back(add);
        }
        void File_Display(ofstream &fileout) {
            for (int i = 0; i < List.size(); i++) {
                List[i].writeToFile(fileout);
                fileout << endl;
            }
        }
        void CountItemsBySize(){
            unordered_map<string, int> sizeCount;
            for (int i = 0; i < List.size(); i++) {
                string size = List[i].getSize();
                sizeCount[size]++;
            }
            // In ra kết quả thống kê
            for (auto it = sizeCount.begin(); it != sizeCount.end(); ++it) {
                cout << "Size: " << it->first << " - Quantity: " << it->second << endl;
            }
        }
        void CountItemsByColor(){
            unordered_map<int, int> ColorCount;
            for(int i=0 ; i < List.size() ; i++ ){
                int color = List[i].getColor();
                ColorCount[color]++;
            }
            for(auto it = ColorCount.begin() ; it != ColorCount.end() ; ++it){
                cout << "Color: " << it->first << " - Quantity: " << it->second << endl;
            }
        }
        ItemsStore FindItem(const string& ID , int color , const string& size){
            for(int i=0 ; i < List.size() ; i++ ){
                if(List[i].getId() == ID && List[i].getColor() == color && List[i].getSize() == size){
                    return List[i];
                }
            }
            return ItemsStore();
        }
};
int main(){
    int n;
    ifstream filein;
    filein.open("input.txt");
    filein >> n;
    if (!filein.is_open()) {
        cout << "Cannot open file input.txt" << endl;
        return 1;
    }
    ListItemsStore List;
    ItemsStore *a;
    a = new ItemsStore[n];
    for(int i=0 ; i<n ; i++){
        a[i].readFromFile(filein);
        List.Add_List(a[i]);
    }
    filein.close();
    ofstream fileout;
    fileout.open("output.txt");
    if(!fileout.is_open()){
        cout << "Cannot open file output.txt " << endl;
        return 1;
    }
    List.File_Display(fileout);
    List.CountItemsBySize();
    cout << endl;
    List.CountItemsByColor();
    string search_ID;
    int search_Color;
    string search_Size;
    cout << "Import Check Search ID: " ; getline(cin , search_ID);
    cout << "Import Check Search Color: " ; cin >> search_Color;
    cin.ignore();
    cout << "Import Check Search Size: " ; getline(cin , search_Size);
    ItemsStore foundItem = List.FindItem(search_ID , search_Color , search_Size);
    if (foundItem.getId() != "") {
        cout << "Found item: ID - " << foundItem.getId() << ", Color - " << foundItem.getColor() << ", Size - " << foundItem.getSize() << endl;
    } else {
        cout << "Item not found." << endl;
    }
    fileout.close();
    return 0;
}