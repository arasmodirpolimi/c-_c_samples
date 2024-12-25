#include <iostream>
#include <vector>
#include <string>

// Component: The base interface for files and directories
class FileSystemEntity {
public:
    virtual void showDetails(int indent = 0) = 0; // Display details
    virtual ~FileSystemEntity() {}
};

// Leaf: Represents a File
class File : public FileSystemEntity {
private:
    std::string name;
public:
    File(const std::string& name) : name(name) {}
    void showDetails(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "File: " << name << std::endl;
    }
};

// Composite: Represents a Directory
class Directory : public FileSystemEntity {
private:
    std::string name;
    std::vector<FileSystemEntity*> children; // Can contain Files or Directories
public:
    Directory(const std::string& name) : name(name) {}

    void add(FileSystemEntity* entity) {
        children.push_back(entity);
    }

    void showDetails(int indent = 0) override {
        std::cout << std::string(indent, ' ') << "Directory: " << name << std::endl;
        for (auto child : children) {
            child->showDetails(indent + 2);
        }
    }

    ~Directory() {
        for (auto child : children) {
            delete child;
        }
    }
};

// Main function
int main() {
    // Create files
    File* file1 = new File("File1.txt");
    File* file2 = new File("File2.txt");
    File* file3 = new File("File3.txt");

    // Create directories
    Directory* dir1 = new Directory("Folder1");
    Directory* dir2 = new Directory("Folder2");
    Directory* root = new Directory("Root");

    // Build the hierarchy
    dir1->add(file1);
    dir1->add(file2);
    dir2->add(file3);
    root->add(dir1);
    root->add(dir2);

    // Show the details of the file system
    root->showDetails();

    // Clean up memory
    delete root;

    return 0;
}
