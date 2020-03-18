#include "Store.h"

Store::Store() {}

Store::~Store() {
    while(!Commands.empty()) {
        auto Temp = Commands.front();
        Commands.pop(); 
        delete Temp;
    }
    for (auto Funny : Comedy) {
        delete Funny;
    }
    for (auto Dramas : Drama) {
        delete Dramas;
    }
    for (auto Classics : Classic) {
        delete Classics; 
    }
}

void Store::verifyMovie(ifstream& FileName) {
    bool SRead = false;
    Movie* Mov = nullptr;
    string Genre;
    cout << "Reading Movies" << endl;

    for (;;) {
        FileName >> Genre;
        if (FileName.eof()) {
            break;
        }
        Genre.pop_back();
        Mov = MovieFactory::create(Genre);
        if (!Mov) {
            lineDiscard(FileName);
            continue;
        }
        SRead = Mov->SetData(FileName);

        if (SRead) {
            addInv(Mov, Genre);
        }
        else {
            delete Mov;
        }
    }
    cout << "Finished Reading Movies" << endl;
}

void Store::verifyCustomer(ifstream& FileName) {
    bool SRead = false;
    Customer* Cust = nullptr;
    cout << "Reading Customers" << endl;

    for (;;) {
        Cust = new Customer();
        SRead = Cust->SetData(FileName);
        if (FileName.eof()) {
            delete Cust;
            break;
        }

        if (SRead) {
            Customers.Add(Cust);
        }
        else {
            delete Cust;
            cout << "Invalid Customer ID" << endl;
        }
    }
    cout << "Finished Reading Customers" << endl;
}

void Store::verifyCommand(ifstream& FileName) {
    string Type;
    bool SRead = false;
    Transaction* Trans = nullptr;
    cout << "Reading Commands" << endl;

    for (;;) {
        FileName >> Type;
        if (FileName.eof()) {
            break;
        }
        Trans = TransactionFactory::create(Type);
        if (!Trans) {
            lineDiscard(FileName);
            continue;
        }
        SRead = Trans->SetData(FileName);
        if (SRead) {
            Commands.push(Trans);
        }
        else {
            lineDiscard(FileName);
            delete Trans;
        }
    }
    cout << "Finished Reading Commands" << endl;
}

bool Store::addInv(Movie* Mov, const string& MovieGenre) {
    return addInvHelper(getInv(MovieGenre), Mov);
}

bool Store::addInvHelper(vector<Movie*>& Container, Movie* Mov) {
    if (Container.empty()) {
        Container.push_back(Mov);
        return true;
    }
    auto Iterator = Container.begin();
    for (auto Temp : Container) { 
        if (*Mov == *Temp) {
            delete Mov;
            return false;
        }
        if (*Mov < *Temp) {
            Container.insert(Iterator, Mov);
            return true;
        }
        Iterator++;
    }
    Container.push_back(Mov);
    return true;
}


void Store::lineDiscard(ifstream& FileName) {
    FileName.ignore(1000, '\n');
}

vector<Movie*>& Store::getInv(const string& MovieGenre) {
    if (MovieGenre == "F") {
        return Comedy;
    }
    if (MovieGenre == "D") {
        return Drama;
    }
    if (MovieGenre == "C") {
        return Classic;
    }
    return Temporary;
}

HashTable& Store::getCustomers() {
    return Customers;
}

void Store::displayInv() {
    cout << " ------------------------------------------" << endl;
    cout << "Comedies: " << endl;
    for (auto Funny : Comedy) {
        Funny->Display();
    }
    cout << " ------------------------------------------" << endl;
    cout << "Dramas: " << endl;
    for (auto Dramas : Drama) {
        Dramas->Display();
    }
    cout << " ------------------------------------------" << endl;
    cout << "Classic: " << endl;
    for (auto Classics : Classic) {
        Classics->Display();
    }
    cout << " ------------------------------------------" << endl;
}

bool Store::storeBuilder(const string& MovieFile, const string& CustomerFile, 
                         const string& CommandFile) {
    cout << "BUILD STORE" << endl;
    ifstream MFile(MovieFile);
    ifstream CFile(CustomerFile);
    ifstream ComFile(CommandFile);

    if (!MFile || !CFile || !ComFile) {
        cout << "Files not found" << endl;
        return false;
    }
    verifyMovie(MFile);
    verifyCustomer(CFile);
    verifyCommand(ComFile);
    cout << "Store Built -- Done" << endl;
    return true;

}

void Store::executeCommand() {
    cout << "Begin Executing Command" << endl;
    while(!Commands.empty()) {
        auto Temp = Commands.front();
        Commands.pop();
        char C = Temp->GetCommand();
        if (C == 'I') {
            displayInv();
            delete Temp;
        }
        else if (C == 'H') {
            Temp->DoTransactionCommand(Temporary, Customers);
            delete Temp;
        }
        else {
            Temp->DoTransactionCommand(getInv(
            Temp->GetTitleMovie()->GetGenre()), Customers);
        }
    cout << "Finished Execution" << endl;
    }
}