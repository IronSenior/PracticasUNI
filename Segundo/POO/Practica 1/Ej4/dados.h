//dados.h
//La clase dados representa el lanzamiento de dos dados

#ifndef DADOS_H
#define DADOS_H

class Dados{
	private:
		int d1_;
		int d2_;
	public:
		Dados();
		void lanzamiento();
		int getDado1();
		int getDado2();
		bool setDado1(int valor);
		bool setDado2(int valor);
		int getSuma();
};

#endif
