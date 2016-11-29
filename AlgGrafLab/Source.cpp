#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;
//ifstream inf("grade.in");

ofstream outf("graf.out");
//---------REZOLVARE PUNCTUL b) cu d)
void matriceAd() {
	ifstream inf("graf.in");
	outf << endl << "Rezolvare (b):" << endl;
	int n, m;
	inf >> n >> m;
	int matrice[10][10] = { 0 };

	int a, b;
	while (!inf.eof()) {
		inf >> a >> b;
		matrice[a - 1][b - 1] = matrice[b - 1][a - 1] = 1;
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			outf << matrice[i][j] << " ";
		outf << endl;
	}
	outf << "\nd)	Grade noduri:\n";
	vector<int>grade;
	int count;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n; j++)
			count += matrice[i][j];
		grade.push_back(count);
	}
	
	for (int i = 0; i < n; i++) {
		outf << "g(" << i + 1 << ") = " << grade[i] << endl;
	}
	inf.close();
}
//---------REZOLVARE PUNCTUL a) cu d)
void listeAd() {
	ifstream inf("graf.in");
	int n, m;
	inf >> n >> m;

	outf << "Rezolvare (a):" << endl;
	map<int, vector<int> >l_adic;

	int from, to;

	while (!inf.eof()) {
		inf >> from >> to;
		if (inf.eof()) break;
		l_adic[from].push_back(to);
		l_adic[to].push_back(from);

	}

	for (int i = 1; i <= n; i++) {
		outf << i << ": ";
		for (unsigned int j = 0; j<l_adic[i].size(); j++)
			outf << l_adic[i][j] << " ";
		outf << endl;
	}

	outf << "\nd)	Grade noduri\n";
	vector<int>grade;
	for (int i = 1; i <= n; i++)
	{
		grade.push_back(l_adic[i].size());
	}

	for (int i = 0; i < n; i++) {
		outf << "g(" << i+1 << ") = " << grade[i]<<endl;
	}
	inf.close();
}
//---------REZOLVARE PUNCTUL c) cu d)
void listaM() {
	ifstream inf("graf.in");
	int n, m;
	inf >> n >> m;
	outf << endl << "Rezolvare (c):" << endl;
	vector<pair<int, int> >lista;

	int a, b;
	while (!inf.eof()) {
		inf >> a >> b;
		if (inf.eof()) break;
		pair<int, int>muchie(a, b);
		lista.push_back(muchie);
	}

	for (unsigned int i = 0; i<lista.size(); i++)
		outf << "(" << lista[i].first << "," << lista[i].second << ")" << " ";

	int vector[10] = { 0 };
	for (unsigned int i = 0; i < lista.size(); i++) {
		vector[lista[i].first-1]++;
		vector[lista[i].second-1]++;
	}
	outf << "\nd)	Grade noduri:\n";
	for (int i = 0; i < n; i++)
	{
		outf << "g(" << i + 1 << ") = " << vector[i] << endl;
	}
	inf.close();
}
//---------REZOLVARE PUNCTUL e)
void bf() {
	ifstream inf("graf.in");
	int n, m;
	inf >> n >> m;
	outf << endl << "Rezolvare (e):" << endl;
	int vizitat[10] = {0};
	queue<int>coada;

	int matrice[10][10] = { 0 };

	int a, b;
	while (!inf.eof()) {
		inf >> a >> b;
		matrice[a - 1][b - 1] = matrice[b - 1][a - 1] = 1;
	}

	coada.push(1);
	int k = 1;
	vizitat[0] = 1;
	outf << "BF: " << coada.front()<<" ";
	while (!coada.empty()) {
		for (int j = 0; j < 10; j++)
		{
			if (matrice[k-1][j] && vizitat[j]==0) {
				coada.push(j+1);
				vizitat[j] = 1;
			}
		}
		coada.pop();
		if (coada.empty()) break;
		k = coada.front();
		outf << k << " ";
	}
	inf.close();
}
//---------REZOLVARE PUNCTUL f)
void df() {  //*****************DOES NOT WORK YET
	ifstream inf("graf.in");
	int n, m;
	inf >> n >> m;
	outf << endl << "Rezolvare (f):" << endl;
	int vizitat[10] = { 0 };
	
	stack<int>stiva;

	int matrice[10][10] = { 0 };

	int a, b;
	while (!inf.eof()) {
		inf >> a >> b;
		matrice[a - 1][b - 1] = matrice[b - 1][a - 1] = 1;
	}

	stiva.push(1);
	outf << "DF: ";
	int numarCiclare, pop;
	while (!stiva.empty()) {
		numarCiclare = stiva.top();
		if (!vizitat[numarCiclare - 1]) {
			outf << numarCiclare << " ";
			vizitat[numarCiclare - 1] = 1;
		}
		pop = 1;
		for (int j = 0; j < 10; j++)
		{
			if (matrice[numarCiclare - 1][j] && vizitat[j] == 0) {
				stiva.push(j + 1);
				pop = 0;
				break;
			}
		}
		if(pop)
			stiva.pop();
		if (stiva.empty()) break;
	}
	inf.close();
}
//-----------REZOLVARE PUNCTUL g)
void bfs(int a[], int nod,int mat[][10]) {
	for (int i = 0; i < 10; i++)
	{
		if (mat[nod][i] && a[i] == 0) {
			outf << i+1 << " ";
			a[i] = 1;
			bfs(a,i,mat);
		}
	}
}
void compConex() {
	ifstream inf("conex.in");
	int n, m;
	inf >> n >> m;
	outf << endl << "Rezolvare (g):" << endl;
	int vizitat[10] = { 0 };
	//queue<int>coada;

	int matrice[10][10] = { 0 };

	int a, b;
	while (!inf.eof()) {
		inf >> a >> b;
		matrice[a - 1][b - 1] = matrice[b - 1][a - 1] = 1;
	}
	int compCon = 0, nrComp=1;
	for (int i = 0; i < n; i++) {
		if (!vizitat[i]) {
			outf << "Componenta " << nrComp << ": ";
			outf << i + 1 << " ";
			vizitat[i] = 1;
			compCon++;
			bfs(vizitat, i, matrice);
			nrComp++;
			outf << endl;
		}
	}
	outf << "Graful are " << compCon << " componente conexe." << endl;
	inf.close();
}
//------------REZOLVARE PUNCTUL h)
void bipartit() {
	ifstream inf("graf.in");
	int n, m;
	inf >> n >> m;
	outf << endl << "Rezolvare (h):" << endl;
	int vizitat[10] = { 0 };
	queue<int>coada;

	int matrice[10][10] = { 0 };

	int a, b;
	while (!inf.eof()) {
		inf >> a >> b;
		matrice[a - 1][b - 1] = matrice[b - 1][a - 1] = 1;
	}
	int colors[10] = { 0 };

	coada.push(0);
	int k = 0;
	vizitat[0] = 1;
	colors[0] = 1;
	bool bipart = true;
	while (!coada.empty()) {
		for (int j = 0; j < n; j++)
		{
			if (matrice[k][j]) {
				if (colors[coada.front()] == colors[j]) {
					bipart = false;
					break;
				}
			}
			if (matrice[k][j] && vizitat[j] == 0) {
				coada.push(j);
				vizitat[j] = 1;
				colors[j] = colors[coada.front()] * -1;
			}
		}
		if (!bipart) {
			outf << "Graful nu e bipartit" << endl; break;
		}
		coada.pop();
		if (coada.empty()) break;
		k = coada.front();
	}
	if (bipart) {
		outf << "Graful e bipartit"<<endl;
		for (int i = 0; i < n; i++)
		{
			outf << "Nodul " << i + 1 << " cu culoarea " << colors[i] << endl;
		}
	}
	inf.close();
}
//------------REZOLVARE PUNCTUL i)
void neorientat() {
	ifstream inf("grade.in");
	vector<int>vect;
	outf << "\nRezolvare (i):\n";
	int n = 0, a;
	while (!inf.eof()) {
		inf >> a;
		vect.push_back(a);
	}
	int sum = 0;
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		sum += vect[i];
	}
	sum % 2 ? outf << "Nu poate fi graf neorientat" << endl : outf << "Poate fi graf neorientat" << endl;
	vect.clear();
	inf.close();
}
//------------REZOLVARE PUNCTUL j)
bool SumNoduri() {		//Functia de verificare a paritatii sumei gradelor
	ifstream inf("grade.in");
	vector<int>vect;
	int a;
	while (!inf.eof()) {
		inf >> a;
		if (inf.eof()) break;
		vect.push_back(a);
	}
	int sum = 0;
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		sum += vect[i];
	}
	if (sum % 2) {
		vect.clear();
		inf.close();
		return false;
	}		//daca e impar =>false
	else {
		vect.clear();
		inf.close();
		return true;		//dace e par => true
	}
}
bool ValGrade() {					//functia ce verifica daca un nod are un numar mai mare sau egal de muchii decat numarul nodurilor
	ifstream inf("grade.in");
	vector<int>vect;
	int a;
	while (!inf.eof()) {
		inf >> a;
		vect.push_back(a);
	}
	for (unsigned int  i = 0; i < vect.size(); i++)
	{
		if (vect[i] >= vect.size()) {
			vect.clear();
			inf.close();
			return false;
		}
	}
	vect.clear();
	inf.close();
	return true;
}
void grafSimplu() {
	outf << "\nRezolvare (j):\n";
	ifstream inf("grade.in");
	if (!SumNoduri()) {
		outf << "Nu poate fi graf simplu, suma gradelor nodurilor nu e para.\n";
		return;
	}
	if (!ValGrade())
	{
		outf << "Nu poate fi graf simplu, un nod are muchii multiple.\n";
		return;
	}
									//facem un vector de perechi (gradul/nodul)
	vector<pair<int,int>>vect;
	int a;
	unsigned int i = 1;
	pair<int, int>pereche;
	while (!inf.eof()) {
		inf >> a;
		if (inf.eof()) break;
		pereche.first = a;
		pereche.second = i;
		vect.push_back(pereche);
		i++;
	}

	bool conditie = true, succes;
	do {
		conditie = true;
		for ( i = 0; i < vect.size(); i++)		//daca vreun grad a scazut sub 0 oprim procedeul
		{
			if (vect[i].first < 0) {
				conditie = false;
				break;
			}
		}
		if (!conditie) break;

		succes = true;								//verificam daca avem 0 peste tot
		for ( i = 0; i < vect.size(); i++)
		{
			if (vect[i].first != 0)
			{
				succes = false;
				break;
			}
		}
		if (succes) break;
													//ordonare desc
		int temp;
		for (int p = 0; p < vect.size()-1; p++)
		{
			for (int k = p+1; k < vect.size(); k++)
			{
				if (vect[p].first < vect[k].first) {
					temp = vect[p].first;
					vect[p].first = vect[k].first;
					vect[k].first = temp;
					temp = vect[p].second;
					vect[p].second = vect[k].second;
					vect[k].second = temp;
				}
			}
		}

		int k;
		k = vect[0].first;
		vect[0].first = 0;
		outf << "\n";
		if (k == 0) {
			succes = false;
			break;
		}
		else {
			for (i = 1; i <= k; i++)
			{
				vect[i].first -= 1;
				outf << "(" << vect[0].second << "," << vect[i].second << ")" << " ";
			}
		}
	} while (conditie);
	if (succes)
	{
		outf << "\nGraful poate fi simplu\n";
	}
	if (!conditie) {
		outf << "\nGraful nu poate fi simplu\n";
	}
	vect.clear();
	inf.close();
}
//---------------Rezolvare punctul k)
void arbore() {
	outf << "\nRezolvare (k):\n";
	ifstream inf("grade.in");
	vector<int>vect;
	int a;
	while (!inf.eof())
	{
		inf >> a;
		if (inf.eof()) break;
		vect.push_back(a);
	}
	bool conditie1 = true,conditie2=true;
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		if (vect[i] <= 0) {
			conditie1 = false;
			break;
		}
		if ( vect[i] >= vect.size())
		{
			conditie2 = false;
			break;
		}
	}
	if (!conditie1) {
		outf << "Graful nu poate fi arbore, prezinta noduri izolate\n";
		return;
	}
	if (!conditie2) {
		outf << "Graful nu poate fi arbore, prezinta sau muchii multiple\n";
		return;
	}
	if (!SumNoduri()) {
		outf << "Nu poate fi arbore, suma gradelor nodurilor nu e para.\n";
		return;
	}
	int sum = 0;
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		sum += vect[i];
	}
	if (sum == 2 * (vect.size() - 1)) {
		outf << "Graful poate fi arbore\n";
	}
	else {
		outf << "Graful nu poate fi arbore\n";
	}
	vect.clear();
	inf.close();
}
//---------------Rezolvare punctul l)
void grSimpluConex() {
	outf << "\nRezolvare (l):\n";
	ifstream inf("grade.in");
	vector<int>vect;
	int a;
	while (!inf.eof())
	{
		inf >> a;
		if (inf.eof()) break;
		vect.push_back(a);
	}
	bool conditie1 = true, conditie2 = true;
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		if (vect[i] <= 0) {
			conditie1 = false;
			break;
		}
		if (vect[i] >= vect.size())
		{
			conditie2 = false;
			break;
		}
	}
	if (!conditie1) {
		outf << "Graful nu poate fi arbore, prezinta noduri izolate\n";
		return;
	}
	if (!conditie2) {
		outf << "Graful nu poate fi arbore, prezinta sau muchii multiple\n";
		return;
	}
	int sum = 0;
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		sum += vect[i];
	}
	if (sum >= 2 * (vect.size() - 1)) {
		outf << "Graful poate fi graf conex simplu\n";
	}
	else {
		outf << "Graful nu poate fi graf conex simplu\n";
	}
	vect.clear();
	inf.close();
}
//---------------Rezolvare punctul m)
void Kruskal() {
	ifstream inf("graf_ponderat.in");
	outf << "\nRezolvare (m):\n";
	vector<vector<int>>vect;
	vector<int>linie;
	int noduri, muchii;
	int temp;
	inf >> noduri >> muchii;
	for (int i = 0; i < muchii; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inf >> temp;
			linie.push_back(temp);
		}
		vect.push_back(linie);
		linie.clear();
	}
	vector<int>r;
	for (int i = 0; i < noduri; i++)
	{
		r.push_back(i);
	}

	for (unsigned int  i = 0; i < vect.size()-1; i++)
	{
		for (unsigned int j = i+1; j < vect.size(); j++)
		{
			if (vect[i][2] > vect[j][2]) {
				vect[i].swap(vect[j]);
			}
		}
	}

	outf << "Kruskal:\n";
	bool conditie = true;
	int ciclare = 0;
	int counter = 0;
	int min,max;
	while (counter<noduri-1) {
		if (r[vect[ciclare][0]-1] == r[vect[ciclare][1]-1]) {
			ciclare++;
		}
		else {
			outf <<"("<< vect[ciclare][0] << "," << vect[ciclare][1] << "," << vect[ciclare][2]<<")" << endl;
			min = vect[ciclare][0] < vect[ciclare][1] ? vect[ciclare][0] : vect[ciclare][1];
			max = vect[ciclare][0] > vect[ciclare][1] ? vect[ciclare][0] : vect[ciclare][1];
			for (unsigned int j = 0; j < r.size(); j++)
			{
				if (r[j] == max-1) {
					r[j] = min-1;
				}
			}
			ciclare++;
			counter++;
		}
	}
	inf.close();
}
//---------------Rezolvare punctul n)
bool esteInCoada(vector<int>&Coad, int valoare) {
	for (unsigned int i = 0; i < Coad.size(); i++)
	{
		if (Coad[i] == valoare)
			return true;
	}
	return false;
}
void Prim() {
	ifstream inf("graf_ponderat.in");			//citim si retinem datele din fisier
	outf << "\nRezolvare (n):\n";
	vector<vector<int>>vect;
	vector<int>linie;
	int noduri, muchii;
	int temp;
	inf >> noduri >> muchii;
	for (int i = 0; i < muchii; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inf >> temp;
			linie.push_back(temp);
		}
		vect.push_back(linie);
		linie.clear();
	}
	vector<int>cheie;					//initializam vectorii p si cheie cu NULL si infinit
	vector<int>p;

	int temp1 = std::numeric_limits<int>::max();
	int temp2= std::numeric_limits<int>::min();
	for (unsigned int i = 0; i < noduri; i++)
	{
		cheie.push_back(temp1);
		p.push_back(temp2);
	}
									//alg prorpiu-zis
	int nod1, nod2,costMinim;
	bool conditie = true;
	vector<int>coada;
	coada.push_back(1);
	cheie[0] = 0;
	outf << "Prim:\n";
	while (conditie) {
		conditie = false;
		costMinim = std::numeric_limits<int>::max();
		for (unsigned int i = 0; i < vect.size(); i++)
		{
			if (coada.back() == vect[i][0] && (!esteInCoada(coada,vect[i][1]))) {
				if (vect[i][2] < cheie[vect[i][1] - 1]) {
					cheie[vect[i][1] - 1]= vect[i][2] ;
					p[vect[i][1] - 1] = vect[i][0];
					conditie = true;
				}
				else {
					continue;
				}
				continue;
			}
			if (coada.back() == vect[i][1]&& !esteInCoada(coada, vect[i][0])) {
				if (vect[i][2] < cheie[vect[i][0] - 1]) {
					cheie[vect[i][0] - 1] = vect[i][2];
					p[vect[i][0] - 1] = coada.back();
					conditie = true;
				}
				else {
					continue;
				}
			}
		}
		if (!conditie)break;

		for (unsigned int i = 1; i < cheie.size(); i++)
		{
			if (costMinim > cheie[i] &&!esteInCoada(coada,i+1)) {
				costMinim = cheie[i];
				nod2 = i;
			}
		}

		outf << "(" << p[nod2] << "," << nod2 + 1 << "," << costMinim << ")\n";
		coada.push_back(nod2 + 1);
	}
	inf.close();
}
//---------------Rezolvare punctul o)
void drum(int initial,vector<int>&tati) {
	if (tati[tati[initial]-1])
	{
		drum(tati[initial]-1, tati);
	}
	outf << tati[initial] << " ";
}
void dijkstra() {
	ifstream inf("graf_orientat_ponderat.in");			//citim si retinem datele din fisier
	outf << "\nRezolvare (o):\n";
	vector<vector<int>>vect;
	vector<int>linie;
	int noduri, muchii;
	int temp;
	inf >> noduri >> muchii;
	for (int i = 0; i < muchii; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inf >> temp;
			linie.push_back(temp);
		}
		vect.push_back(linie);
		linie.clear();
	}
	inf.close();

	vector<int>d;							//definim ceilalti vectori si facem initializarea lor
	vector<int>tata;
	vector<int>vizitat;
	int infinit = std::numeric_limits<int>::max();

	d.push_back(0);
	tata.push_back(0);
	vizitat.push_back(1);
	for (unsigned int i = 0; i < noduri-1; i++)
	{
		d.push_back(infinit);
		tata.push_back(-1);
		vizitat.push_back(0);
	}
											//alg propriu-zis
	outf << "Dijkstra:\n";
	bool ok = true;
	int min,k=0;

	for (unsigned int i = 0; i < vect.size(); i++)
	{
		if (vect[i][0] == k + 1) {
			d[vect[i][1] - 1] = vect[i][2];
			tata[vect[i][1] - 1] = vect[i][0];
		}
	}

	outf << k + 1 << " cost: " << "x" << " | drum: x"<<endl;

	while (ok)
	{
		min = infinit;
		for (unsigned int i = 0; i < noduri; i++)
		{
			if (!vizitat[i] && min > d[i]) {
				min = d[i];
				k = i;
			}
		}
			if (min!=infinit)
			{
				vizitat[k] = 1;
				for (unsigned int i = 0; i < vect.size(); i++)
				{
					if (vect[i][0] == k + 1) {
						for (unsigned int j = 0; j < vizitat.size(); j++)
						{
							if (!vizitat[j] &&j+1==vect[i][1] &&d[j] > d[k] + vect[i][2]) {
								d[j] = d[k] + vect[i][2];
								tata[j] = k + 1;
							}
						}
					}
				}
			}
			else {
				ok = false;
			}
			if (!ok)break;
			outf << k + 1 << " cost: " << d[k] << " | drum: ";
			drum(k, tata);
			outf <<k+1<< endl;
	}
}
//---------------Rezolvare punctul p)
void floyd() {
	ifstream inf("graf_floyd.in");			//citim si retinem datele din fisier
	outf << "\nRezolvare (p):\n";
	vector<vector<int>>vect;
	vector<int>linie;
	int noduri, muchii;
	int temp;
	inf >> noduri >> muchii;

	unsigned long int costuri[10][10];
	int a, b;
	int infinit = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i <= noduri; i++) {
		linie.push_back(infinit);
	}
	for (unsigned int i = 0; i <=noduri; i++) {
		vect.push_back(linie); vect[i][i] = 0;
	}


	for (unsigned int i = 1; i <= muchii; i++)
	{
		inf >> a >> b;
		inf >> vect[a][b];
	}

	for (unsigned int k = 1; k <=noduri; k++)
	{
		for (unsigned int i = 1; i <=noduri; i++)
		{
			for (unsigned int j = 1; j <=noduri; j++)
			{
				if (vect[i][k] != infinit && vect[k][j] != infinit)
					if (vect[i][j]>vect[i][k] + vect[k][j])
					{
						vect[i][j] = vect[i][k] + vect[k][j];
					}
			}
		}
	}

	inf.close();
	outf << "Floyd-Warshall;\n";
	for (unsigned int i = 1; i <= noduri; i++)
	{
		outf << i << " cost: ";
		for (unsigned int j = 1; j <= noduri; j++)
		{
			outf<<vect[i][j] << " ";
		}
		outf << endl;
	}

	vect.clear();
}
//*************************rezolvare q)
int cateGrade(vector<pair<int, int>>& vect,int valoare) {
	for (unsigned int i = 1; i < vect.size(); i++)
	{
		if (vect[i].first == valoare)
			return vect[i].second;
	}
	return 0;
}

int muchie(vector<vector<int>>&matrice, int grad, vector<pair<int, int>>&vectGrade) {
	int memo=0;
	for (unsigned int i = 1; i < matrice[grad].size(); i++)
	{
		if (matrice[grad][i]) {
			memo = i;
			if (cateGrade(vectGrade, i) < 2)
				continue;
			else
				return i;
		}
	}
	return memo;
}

void fleury() {
	outf << "\nRezolvare (q):\nFleury:\n";
	ifstream inf("fleury.in");
	int noduri, muchii;

	inf >> noduri >> muchii;

	vector<vector<int>>matrice;
	vector<int>linie;
										//CITIRE MATRICE	
	for (unsigned int i = 0; i < noduri+1; i++)
	{
		linie.push_back(0);
	}
	for (unsigned int i = 0; i < noduri + 1; i++)
	{
		matrice.push_back(linie);
	}
	
	int a, b;
	for (unsigned int i = 0; i < muchii; i++)
	{
		inf >> a >> b;
		matrice[a][b] = matrice[b][a]=1;
	}
							//	RETINEM GRADELE
	pair<int, int>grade;
	vector<pair<int, int>>vectGrade;
	grade.first = grade.second = 0;
	vectGrade.push_back(grade);
	int counter = 0;
	for (unsigned int i = 1; i < matrice.size(); i++)
	{
		counter = 0;
		for (unsigned int j = 1; j < matrice[i].size(); j++)
		{
			if (matrice[i][j])counter++;
		}
		grade.first = i;
		grade.second = counter;
		vectGrade.push_back(grade);
	}

	queue<int>path;
	
	for (unsigned int i = 1; i < vectGrade.size(); i++)
	{
		if (vectGrade[i].second % 2) {
			path.push(vectGrade[i].second);
			break;
		}
	}
	path.push(1);
	int grad;
	while (!path.empty())
	{
		outf << path.front()<<" ";
		grad = muchie(matrice, path.front(), vectGrade);
		if (!grad)break;
		path.push(grad);
		vectGrade[grad].second--;
		vectGrade[path.front()].second--;
		matrice[grad][path.front()] = matrice[path.front()][grad] = 0;
		path.pop();
	}
	if (!grad) outf << "Nu se poate forma un ciclu eulerian!\n";
	inf.close();
}
//---------------------MAIN----------------------
int main()
{
	listeAd();
	matriceAd();
	listaM();
	bf();
	df();
	compConex();
	bipartit();
	neorientat();
	grafSimplu();
	arbore();
	grSimpluConex();
	Kruskal();
	Prim();
	dijkstra();
	floyd();
	fleury();
	return 0;
}
