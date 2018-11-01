//dados.h
//La clase dados representa el lanzamiento de dos dados

#ifndef DADOS_H
#define DADOS_H

#include <list>
using std::list;


class Dados{
	private:
		int d1_;
		int d2_;
		int lanzdado1_;
		int lanzdado2_;
		int d1Suma_;
		int d2Suma_;
		list<int> vultimos1_;
		list<int> vultimos2_;
		void savelanzamiento1_(int lanz);
		void savelanzamiento2_(int lanz);

	public:
		Dados();
		void lanzamiento();
		inline int getDado1() const {return d2_;};
		inline int getDado2() const {return d2_;};
		bool setDado1(int valor);
		bool setDado2(int valor);
		int getSuma();
		inline int getLanzamientos1() const {return lanzdado1_;};
		inline int getLanzamientos2() const {return lanzdado2_;};
		float getMedia1();
		float getMedia2();

		//Devuelven la lista de los 5 ultimos lanzamientos
		//El último elemento de la lista es el último lanzamiento
		//No cuenta como lanzamiento el setDadox
		inline list<int> getVultimos1() const {return vultimos1_;};
		inline list<int> getVultimos2() const {return vultimos1_;};
};

#endif
