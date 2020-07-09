#include<iostream>
#include<unordered_map>

using namespace std;

class node{
public:
    char data;
    bool end;
    unordered_map<char, node*> children;
};

class trie{
private:
    node* root;
    int words;
    int nodes;

    void add(node* temp, string word, int index){
        if(index == word.length()){
            words++;
            temp->end = true;
            return;
        }

        char ch = word[index];

        if(temp->children.count(ch) == 0){
            nodes++;

            node* nn = new node();
            nn->data = ch;
            nn->end = false;

            temp->children[ch] = nn;
            add(nn, word, index + 1);
        } else {
            add(temp->children[ch], word, index + 1);
        }
    }

    bool search(node* temp, string word, int index){
        if(index == word.length()){
            return temp->end;
        }

        char ch = word[index];

        if(temp->children.count(ch) == 0){
            return false;
        }

        node* child = temp->children[ch];
        return search(child, word, index + 1);
    }

    void display(node* temp, string wsf){
        if(temp->end == true){
            cout << wsf << endl;
        }
        
        unordered_map<char, node*> children = temp->children;
        for(auto itr : children){
            display(itr.second, wsf + itr.first);
        }
    }

    void displayTree(node* root){
        if(root->children.size() == 0){
            return;
        }

        cout << root->data << " -> ";
        
        for(auto itr : root->children){
            cout << itr.first << (itr.second->end) ? " *" : " ";
        }
        cout << endl;

        for(auto itr : root->children){
            displayTree(itr.second);
        }
    }

    void remove(node* temp, string word){
        if(word.size() == 0){
            temp->end = false;
            words--;
            return;
        }
        
        char ch = word[0];

        remove(temp->children[ch], word.substr(1));

        if(temp->children[ch]->end == false && temp->children[ch]->children.size() == 0){
            node* rem = temp->children[ch];

            temp->children.erase(ch);
            nodes--;
            delete rem;
        }
    }
    
public:
    trie(){
        root = new node();
        root->data = '$';
        words = 0;
        nodes = 1;
    }

    void add(string word){
        if(!search(word))
            add(root, word, 0);
    }

    bool search(string word){
        return search(root, word, 0);
    }

    void display(){
        display(root, "");
    }

    void displayTree(){
        displayTree(root);
    }

    void remove(string word){
        if(search(word))
            remove(root, word);
    }
};

int main(int argc, char** argv){
    trie tr;

    tr.add("seen");
    tr.add("see");
    tr.add("sea");
    tr.add("add");
    tr.add("ant");
    tr.add("and");
    tr.add("as");
    tr.add("ask");

    cout << tr.search("seek") << endl;

    tr.display();
    // tr.displayTree();

    tr.remove("as");
    tr.displayTree();
    cout << " ------------------- " << endl;
    tr.remove("ask");
    tr.displayTree();

    cout << " ------------------- " << endl;

    tr.display();
}