#include "Person.h"

using namespace std;

Person::Person()
{

    id = rand() % 9999999 + 1;
    name = names[rand() % 182];
    level = "Seed-Spawn";

}

Person::Person(int id, string nm, string lvl)
    :id(id), name(nm), level(lvl)
{

}

Person::~Person()
{

}

void Person::print()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}

void Person::save(ofstream &myStream)
{
    myStream << id << "|"
             << name << "|"
             << level << "|";
}


bool Person::operator==(const Person& otherPerson)
{
    return (this->id == otherPerson.id);
}

bool Person::operator<=(const Person& otherPerson)
{
    return (this->id <= otherPerson.id);
}

bool Person::operator>=(const Person& otherPerson)
{
    return (this->id >= otherPerson.id);
}

bool Person::operator!=(const Person& otherPerson)
{
    return (this->id != otherPerson.id);
}

bool Person::operator>(const Person& otherPerson)
{
    return (this->id > otherPerson.id);
}

bool Person::operator<(const Person& otherPerson)
{
    return (this->id < otherPerson.id);
}

//Some fun
static const string data[182] = {"Abholos", "Alala", "Ammutseba", "Amon-Gorloth", "Aphoom-Zhah",
"Arwassa", "Atlach-Nacha", "Ayi'ig", "Aylith", "Baoht Z'uqqa-Mogg", "Basatan", "B'gnu-Thun", "Bokrug", "Bugg-Shash", "Byatis", "Chaugnar Faugn", "Caug-Narfagn", "Coatlicue", "Coinchenn", "Crom Cruach", "Cthaat", "Cthaeghya", "Cthugha", "Cthulhu", "Cthylla", "Ctoggha", "Cyäegha", "Cynothoglys", "Dhumin", "Dygra", "Dythalla", "Dzéwà", "Eihort The Pale Beast", "Ei'lor", "Etepsed Egnis", "Ghadamon", "Ghatanothoa", "Ghisguth", "Gi-Hoveg", "Glaaki", "Gleeth", "Gloon", "Gobogeg", "Gog-Hoor", "Gol-goroth", "Golothess", "Groth-Golka", "Gtuhanai", "Gurathnaka", "Gur'la-ya", "Gwarloth", "Gzxtyos", "Hastalÿk", "Hastur The Unspeakable, He Who is Not to be Named, Lord of Interstellar Spaces, The King in Yellow, The Peacock King, Zukala-Koth", "H'chtelegoth", "Haiogh-Yai", "Hnarqu", "Hziulquoigmnzhah", "Idh-yaa", "Inpesca", "Iod", "Istasha", "Ithaqua", "Janai'ngo", "Juk-Shabb", "Kaalut", "Kag'Naru of the Air", "Kassogtha", "Kaunuzoth", "Khal'kru", "Klosmiebhyx", "K'nar'st", "Krang", "Kthaw'keth", "Kurpannga", "Lam	The Grey", "Lexur'iga-serr'roth", "Lythalia", "Mappo no Ryujin", "M'basui Gwandu", "M'Nagalah", "Mnomquah", "Mordiggian", "Mormo", "Mortllgh", "Mynoghra", "Nctosa & Nctolhu", "Ngirrth'lu", "Northot", "Nssu-Ghahnb", "Nug and Yeb", "Nyaghoggua", "Nycrama", "Nyogtha", "Ob'mbu", "Oorn", "Othuum", "Othuyeg", "Perse", "Pharol", "Poseidon", "Psuchawrl", "Ptar-Axtlan", "Quachil Uttaus", "Quyagen	The Eye of Z'ylsm", "Q'yth-az", "Raandaii-B'nk", "Ragnalla", "Raphanasuan", "Rhagorthua", "Rhan-Tegoth", "Rhogog", "Rh'Thulla of the Wind", "Rlim Shaikorth", "Rokon", "Saaitii", "Scathach", "Sebek", "Sedmelluq", "Sfatlicllp", "Shaklatal", "Shathak", "Shaurash-Ho", "Sheb-Teth", "Shista", "Shlithneth", "Sho-Gath", "Shterot", "Shudde M'ell", "Shuy-Nihl", "Sthanee	The Lost One", "S'tya-Yg'Nalle", "Summanus", "Swarog", "Thanaroa", "Tharapithia", "Thasaidon", "Thog", "Toth", "Th'rygh", "Tsathoggua", "Zhothaqqua", "Tulushuggua", "Turua", "Uitzilcapac", "Ut'Ulls-Hr'Her", "Vhuzompha", "Vibur", "Vile-Oct", "Volgna-Gath", "Voltiyig", "Vthyarilops", "Vulthoom", "Xalafu", "Xcthol", "Xinlurgash", "Xirdneth", "Xitalu", "Xotli", "Xoxiigghua", "Yegg-Ha", "Y'golonac", "Yhagni", "Yhashtur", "Yig", "Y'lla", "'Ymnar", "Yog-Sapha", "Yorith", "Ysbaddaden", "Ythogtha", "Yug-Siturath", "Zathog", "Zhar and Lloigor", "Zindarak", "Zoth-Ommog", "Zstylzhemghi", "Zystulzhemgni", "Zushakon", "Zul-Che-Quon", "Z'toggua", "Zvilpogghua"
};
const string* Person::names = data;
