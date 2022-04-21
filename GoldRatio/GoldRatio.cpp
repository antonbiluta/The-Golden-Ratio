#include <iostream>
using namespace std;

double w = (3 - sqrt(5)) / 2;

double f(double x)
{
	return x * x + 6 * x + 13;
}

int main()
{
	double a_start = -6, b_end = 4;
	double eps = 0.5;
	double l = 2 * eps;
	double k = 0;
	double y, z;
	double fy, fz;
	double L;
	setlocale(LC_ALL, "Russian");

	cout << "Шаг 1. Зададим начальный интервал неопределенности L0=[a0,b0]" << endl;
	cout << "Начальный интервал неопределенности [" << a_start << ", " << b_end << "]" << endl;
	cout << "Зададим допустимую погрешность " << endl;
	cout << "Epsilant = " << eps << endl;
	cout << "Точность l = " << l << endl;
	cout << endl;

	cout << "Шаг 2. Положим k = " << k << endl;
	cout << endl;

	cout << "Шаг 3. Вычислим Ук, Zк: " << endl;
	y = a_start + w * (b_end - a_start);
	cout << "y = " << y << endl;
	z = a_start + b_end - y;
	cout << "z = " << z << endl;
	cout << endl;
	fy = f(y);
	fz = f(z);
	while ((b_end - a_start) > l) {

		cout << "Шаг 4. Вычислм f(Ук), f(Zк): " << endl;
		cout << "f(y) = " << fy << " " << "f(z) =  " << fz << endl;
		cout << endl;
		cout << "Шаг 5. Сравним f(Ук) с f(Zк): " << endl;

		if (fy <= fz) {

			cout << "Условие а) выполняется! f(y) <= f(z)" << endl;
			a_start = a_start;
			b_end = z;
			cout << "a = " << a_start << endl;
			cout << "b = " << b_end << endl;
			z = y;
			y = a_start + b_end - y;
			fz = fy;
			fy = f(y);
			cout << "y = " << y << endl;
			cout << "z = " << z << endl;
			cout << endl;
			cout << "Шаг 6. Вычислим L=|a(k+1)-b(k+1)| и проверим условие окончания:" << endl;
			L = abs(a_start - b_end);
			cout << "L =" << L << endl;

			if (L <= l) {

				cout << " L <= l, Процесс поиска завершен! Точка минимума принадлежит интервалу:" << endl;
				cout << "[" << a_start << "; " << b_end << "]" << endl;
				cout << "Минимум функции равен : " << (a_start + b_end) / 2 << endl;

			} else {

				cout << "L > l, Положим k = k+1 и вернемся к шагу 4" << endl;
				k++;
				cout << "k = " << k << endl;
				cout << endl;
			}
		} else {

			cout << "Условие б) выполняется! f(y) > f(z)" << endl;
			a_start = y;
			b_end = b_end;
			cout << "a = " << a_start << endl;
			cout << "b = " << b_end << endl;
			y = z;
			z = a_start + b_end - z;
			fy = fz;
			fz = f(z);
			cout << "y = " << y << endl;
			cout << "z = " << z << endl;
			cout << endl;
			cout << "Шаг 5. Вычислим L =|a(k+1)-b(k+1)| и проверим условие окончания:" << endl;
			L = abs(a_start - b_end);
			cout << "L =" << L << endl;

			if (L <= l) {

				cout << " L <= l, Процесс поиска завершен! Точка минимума принадлежит интервалу:" << endl;
				cout << "[" << a_start << "; " << b_end << "]" << endl;
				cout << "Минимум функции равен : " << (a_start + b_end) / 2 << endl;

			} else {

				cout << "L > l, Положим k = k+1 и вернемся к шагу 4" << endl;
				k++;
				cout << "k = " << k << endl;
				cout << endl;

			}
		}
	}
	cout << endl;
	cout << "Интервал неопределенности = [" << a_start << "; " << b_end << "]" << endl;
	cout << "Минимум функции равен : " << (a_start + b_end) / 2 << " +- " << (b_end - a_start) / 2 << endl;
	system("pause");
	return 0;
}