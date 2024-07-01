
#include <iostream>
#include <stdlib.h>


using namespace std;

class NamesList;

class Term {
	friend NamesList;
	char* name;
public:
	Term() {
		name = nullptr;
	}
	Term(const char* str) {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
	char* getName() {
		return name;
	}
	int compareName(Term& t) {
		return strcmp(name, t.name);
	}
};

const int MAX_SIZE = 100;

class NamesList {
public:
	NamesList();
	void NewTerm(const char*);
	int Display();
	int Add(const char*);
	bool Delete(const char*);
	bool Search(const char*);
	void Sort();
	NamesList& Merge(NamesList&);

private:
	static Term* lists;
	static int capacity;
	static int free;
	int start, finish;
	int terms;
};

NamesList::NamesList()
{
	start = -1;
	finish = -1;
	terms = 0;
}

int NamesList::Display() {//coef�� 0�� �ƴ� term �� �ִٰ� �����Ѵ� 
	
	if (start == -1 || finish == -1) {
        cout << "List is empty." << endl;
        return 0;
    }

    int aPos = start;
    while (aPos <= finish) {
        cout << lists[aPos].getName() << endl;
        aPos++;
    }

    return 1;
}

void NamesList::NewTerm(const char* str)
{
	Term* temp = new Term(str);
	lists[free++] = *temp;
}

int NamesList::Add(const char* str) {
    if (free >= MAX_SIZE) {
        cout << "List is full. Cannot add more terms." << endl;
        return 0;
    }

    NewTerm(str);
    finish++;
    terms++;

    return 0; // �׻� 0�� ��ȯ
}



NamesList& NamesList::Merge(NamesList& b) {
	NamesList mergedList;

	// ù ��° ��Ͽ��� ��Ҹ� �����մϴ�.
	for (int i = start; i <= finish; i++) {
		mergedList.Add(lists[i].getName());
	}

	// �� ��° ��Ͽ��� ��Ҹ� �����մϴ�.
	for (int i = b.start; i <= b.finish; i++) {
		mergedList.Add(b.lists[i].getName());
	}

	return mergedList;
}

bool NamesList::Delete(const char* str) {
    // ������ �׸��� ã�� ���� ����Ʈ�� �ݺ��մϴ�.
    for (int i = start; i <= finish; i++) {
        // ���� �׸��� �̸��� ������ ���ڿ��� ��ġ�ϴ��� Ȯ���մϴ�.
        if (strcmp(lists[i].getName(), str) == 0) {
            // ��ġ�ϴ� ��� �ش� �׸��� �����ϰ� ����Ʈ�� �������մϴ�.
            delete[] lists[i].name;
            for (int j = i; j < finish; j++) {
                lists[j] = lists[j + 1];
            }
            finish--;
            terms--;
            return true; // ���� ����
        }
    }
    return false; // ������ �׸��� ����
}

bool NamesList::Search(const char* str) {
    // ����Ʈ�� �ݺ��Ͽ� �Էµ� ���ڿ��� �˻��մϴ�.
    for (int i = start; i <= finish; i++) {
        // ���� �׸��� �̸��� �˻��� ���ڿ��� ��ġ�ϴ��� Ȯ���մϴ�.
        if (strcmp(lists[i].getName(), str) == 0) {
            return true; // �˻� ����
        }
    }
    return false; // �˻� ����
}

void NamesList::Sort() {
    for (int i = start; i < finish; i++) {
        for (int j = start; j < finish - 1; j++) { // ����: �ݺ� ���� ����
            // ���� �׸�� ���� �׸��� ���Ͽ� �����մϴ�.
            if (strcmp(lists[j].getName(), lists[j + 1].getName()) > 0) {
                // ���� �׸��� ���� �׸񺸴� ũ�ٸ� ��ȯ�մϴ�.
                Term temp = lists[j];
                lists[j] = lists[j + 1];
                lists[j + 1] = temp;
            }
        }
    }
}


int NamesList::capacity = 100;
Term* NamesList::lists = new Term[MAX_SIZE];
int NamesList::free = 0;
enum Menu { ADD = 1, DELETE, SEARCH, SORT, MERGE, EXIT };



int main(void) {
	int choice;
	NamesList P1, P2, P3;
	bool result = false;
	const char* nameStrings1[] = { "apple","banana", "cherry" };
	const char* nameStrings2[] = { "melon","blueberry", "persimon" };
	int size1 = sizeof(nameStrings1) / sizeof(nameStrings1[0]);
	int size2 = sizeof(nameStrings2) / sizeof(nameStrings2[0]);
	char* deletedString = "cherry";
	char* searchString = "apple";
	while (true) {
		cout << "\n****** Menu Selection ******" << endl;
		cout << "1.ADD, 2.DELETE, 3.SEARCH, 4.SORT, 5.MERGE, 6.EXIT" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice) {
		case ADD:

			for (int i = 0; i < size1; i++) {
				P1.Add(nameStrings1[i]);
			}
			for (int i = 0; i < size2; i++) {
				P2.Add(nameStrings2[i]);
			}
			P1.Display();
			P2.Display();

			break;
		case DELETE:

			result = P1.Delete(deletedString);
			P1.Display();
			result = P2.Delete(deletedString);
			P2.Display();
			break;
		case SEARCH:

			result = P1.Search(deletedString);
			P1.Display();
			result = P2.Search(deletedString);
			P2.Display();
			break;

		case SORT:
			P1.Sort();
			P2.Sort();
			P1.Display();
			P2.Display();
			break;
			
		case MERGE:
			P3 = P1.Merge(P2);
			P3.Display();
			break;
			
		case EXIT:
			cout << "Good Bye...!!!" << endl;
			exit(0);
		}
	}
	system("pause");
	return 0;
}
