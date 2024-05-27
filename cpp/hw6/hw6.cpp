#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node sınıfı, herhangi bir dosya veya klasörü temsil eder.
class Node {
public:
    string name; // Düğümün adını saklar (dosya veya klasör adı).
    vector<Node*> children; // Bu düğümün çocuklarını saklar, yani alt klasör veya dosyalar.

    // Yapıcı fonksiyon, düğüm oluşturulduğunda isim atanmasını sağlar.
    Node(string name) : name(name) {}

    // Çocuk düğüm (dosya veya klasör) eklemek için kullanılır.
    void addChild(string childName) {
        Node* child = new Node(childName); // Yeni çocuk düğüm oluşturulur.
        children.push_back(child); // Çocuk listesine eklenir.
    }

    // Hiyerarşiyi konsola basmak için kullanılır. Girinti seviyesi ile düzenlenir.
    void display(int level = 0) {
        string indent(level * 2, ' ');  // Seviyeye göre girinti oluşturur.
        cout << indent << "- " << name << endl; // Düğüm adını girintili şekilde yazdırır.
        for (Node* child : children) { // Çocuk düğümleri için döngü.
            child->display(level + 1); // Her çocuk için rekürsif olarak display fonksiyonu çağrılır.
        }
    }

    Node* findNode(const string& nodeName) {
        if (name == nodeName) return this; // Eğer bu düğümün adı aranan adla eşleşiyorsa, bu düğümü döndür.
        for (Node* child : children) {
            Node* foundNode = child->findNode(nodeName); // Rekürsif olarak çocuk düğümleri ara.
            if (foundNode) return foundNode; // Eğer düğüm bulunduysa, döndür.
        }
        return nullptr; // Eğer düğüm bulunamazsa, nullptr döndür.
    }

    void deleteNode(const string& nodeName) {
        for (auto it = children.begin(); it != children.end(); ) {
            if ((*it)->name == nodeName) {
                delete *it;
                it = children.erase(it); // Düğümü bulduğumuzda sil ve çocuklar listesinden çıkar.
            } else {
                (*it)->deleteNode(nodeName); // Rekürsif olarak çocuk düğümleri kontrol et.
                ++it;
            }
        }
    }

    ~Node() {
        for (Node* child : children) {
            delete child; // Belleği temizle
        }
    }
};



int main() {
    Node root("Root");  // Kök dizini olarak "Root" adında bir Node oluşturulur.
    root.addChild("Folder1"); // Kök dizinine "Folder1" adında bir alt klasör eklenir.
    root.children[0]->addChild("File1.txt"); // "Folder1"e "File1.txt" adında bir dosya eklenir.
    root.children[0]->addChild("File2.txt"); // "Folder1"e "File2.txt" adında bir dosya daha eklenir.
    root.addChild("Folder2"); // Kök dizinine "Folder2" adında bir alt klasör daha eklenir.
    root.children[1]->addChild("File3.txt"); // "Folder2"ye "File3.txt" adında bir dosya eklenir.

    cout << "Dosya Hiyerarşisi:" << endl;
    root.display();  // Kök dizinden başlayarak tüm dosya hiyerarşisini gösterir.

    return 0; 
}