#include <iostream>
#include <ctime>
#include <cstdlib>

// #define N 1000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct fun{
	double a;
	double b;
};

using namespace std;
//int main(int argc, char** argv) {
//	srand(time(NULL));
//	double x[N];
//	double y[N];
//	double a = ((double) (rand() % 100)) / ((double) (rand() % 100));
//	cout << a << endl;
//	for(int i = 0 ; i < N ; i++){
//		x[i] = i;
//		y[i] = a * i + (double) (rand()/RAND_MAX);
//	}
//	fun theta = gradient_descent(x, y, 1.0/(N*N*N), 10000, N);
//	cout<<"theta: " << theta.a << " " << theta.b << endl;
//	return 0;
//}


double cost (fun theta, double x[], double y[], int n) {
	double cost = 0;
	for(int i = 0 ; i < n ; i++){
		cost += ((theta.a * x[i] + theta.b - y[i]) * (theta.a * x[i] + theta.b - y[i]));
	}
	return cost;
}

fun gradient_step(fun theta,double x[], double y[], double alpha, int n){
	double delta_a = 0;
	double delta_b = 0;
	for(int i = 0 ; i < n ; i ++){
		delta_a += (theta.a * x[i] + theta.b - y[i]) * x[i] * (2.0/n);
		delta_b += (theta.a * x[i] + theta.b - y[i]) * (2.0/n);
	}
	fun newTheta;
	newTheta.a = theta.a - alpha * delta_a;
	newTheta.b = theta.b - alpha * delta_b;
	return newTheta;
}

fun gradient_descent(double x[], double y[], double alpha, int steps, int n){
	fun theta;
	theta.a = 0;
	theta.b = 0;
	for( int i = 0 ; i < steps; i++){
		theta = gradient_step(theta,x,y,alpha,n);
//		if(i % 1000 == 0) cout<<"current cost: " << cost(theta,x,y,n) << endl;
	}
	return theta;
}

void regress (double x[], double y[], int n){
	gradient_descent(x, y, 1.0/(n*n*n), 10000, n);
}
