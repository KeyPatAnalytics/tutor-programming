#include<iostream> 
#include<cstdlib> 
#include<thread> 
#include<ctime>
#include<cmath>
#include<string>
using namespace std;

void Pi_Leibniz(int n, double arr[], int idx) {
	std::thread::id id = std::this_thread::get_id();
	double res_Temp = (pow(-1.0, n)) / (2 * n + 1);
	arr[idx] = res_Temp;
}

void Pi_Wallis(int n, double arr[], int idx) {
	std::thread::id id = std::this_thread::get_id();
	double res_Temp = (4 * pow(n, 2)) / (4 * pow(n, 2) - 1);
	arr[idx] = res_Temp;
}

void Int_Rect(double x, double w, double arr[], int idx) {
	std::thread::id id = std::this_thread::get_id();
	double res_Temp = pow(x, 2) * w;
	arr[idx] = res_Temp;
}

void Int_Trap(double x1, double x2, double w, double arr[], int idx) {
	std::thread::id id = std::this_thread::get_id();
	double res_Temp = ((pow(x1, 2) + pow(x1, 2)) / 2) * w;
	arr[idx] = res_Temp;
}

void Int_Sims(double x1, double x2, double arr[], int idx) {
	std::thread::id id = std::this_thread::get_id();
	double res_Temp = ((x2 - x1) / 6) * (pow(x1, 2) + 4 * pow(((x1 + x2) / 2), 2) + pow(x2, 2));
	arr[idx] = res_Temp;
}

int main() {
	bool Flag = false;
	int Mode;
	int Mode_Int_1 = 0;
	int Mode_Int_2 = 0;
	int acc_Mode;
	int length = 10;
	double Res = 0.0;
	double ResVrem;
	double x_Start;
	double x_End;
	double x_Mid;
	double x_Space;
	double x_Delta;
	double x_1;
	double x_2;
	double time_pause = 0.0;
	double Accuracy;
	int hardware_threads = std::thread::hardware_concurrency();
	std::cout << "This system can start " << hardware_threads << " threads" << "\n";
	std::cout << "Calculation Types:" << "\n";
	std::cout << "Part 1" << "\n";
	std::cout << "1 - Pi with Leibniz formula" << "\n";
	std::cout << "2 - Pi with Wallis formula" << "\n";
	std::cout << "Part 2" << "\n";
	std::cout << "3 - Integration with Rectangular rule" << "\n";
	std::cout << "4 - Integration with Trapezoidal rule" << "\n";
	std::cout << "5 - Integration with Simpson's rule" << "\n";
	std::cout << "0 - Exit of Program" << "\n";
	std::cout << "---------------------" << "\n";
	std::cout << "Accuracy Method:" << "\n";
	std::cout << "1 - Fixed number of Threads" << "\n";
	std::cout << "2 - Accuracy Method" << "\n";
	std::cout << "---------------------" << "\n";
	while (true) {
		std::cout << "Select the calculation type: ";
		std::cin >> Mode;
		std::cin.ignore();
		std::cout << "Select the accuracy mode: ";
		std::cin >> acc_Mode;
		std::cin.ignore();
		if (acc_Mode == 2)
		{
			std::cout << "Enter required accuracy: ";
			std::cin >> Accuracy;
			std::cin.ignore();
		}
		if (acc_Mode == 2 && (Mode == 3 || Mode == 4 || Mode == 5))
		{
			Mode_Int_1 = Mode;
			std::cout << "The #1 integration type: " << Mode_Int_1 << "\n";;
			std::cout << "The #2 integration type: ";
			std::cin >> Mode_Int_2;
			std::cin.ignore();
			std::cout << "Enter Integration start point: ";
			std::cin >> x_Start;
			std::cin.ignore();
			std::cout << "Enter Integration end point: ";
			std::cin >> x_End;
			std::cin.ignore();
		}
		if (Mode == 0)
		{
			std::cout << "End of Program" << "\n";
			std::cin.ignore();
			break;
		}
		else
		{
			int start = clock();
			if (acc_Mode == 1) {
				std::cout << "Calculation type " << Mode << " started" << "\n";
			}
			thread::id id;
			double Result_Vrem = 0.0;
			if (acc_Mode == 2) {
				length = 1;
			}
			while (true) {
				Flag = false;
				thread* thread_array = new thread[length];
				thread* thread_array_Alt = new thread[length];
				double* res_arr = new double[length];
				double* res_arr_Alt = new double[length];
				for (int i = 0; i < length; i++) {
					res_arr[i] = 0.0;
					res_arr_Alt[i] = 0.0;
				}
				if (Mode == 1) {
					for (int i = 0; i < length; i++) {
						thread_array[i] = thread(Pi_Leibniz, i, res_arr, i);
					}
				}
				if (Mode == 2) {
					for (int i = 0; i < length; i++) {
						thread_array[i] = thread(Pi_Wallis, (i + 1), res_arr, i);
					}
				}
				if (Mode == 3 || Mode_Int_1 == 3 || Mode_Int_2 == 3) {
					std::cout << "Mode 3 - Integration with Rectangular rule case" << "\n";
					int start_pause = clock();
					if (acc_Mode == 1) {
						std::cout << "Enter Integration start point: ";
						std::cin >> x_Start;
						std::cin.ignore();
						std::cout << "Enter Integration end point: ";
						std::cin >> x_End;
						std::cin.ignore();
					}
					int end_pause = clock();
					x_Space = x_End - x_Start;
					x_Delta = x_Space / length;
					if (Flag == true) {
						for (int i = 0; i < length; i++) {
							x_Mid = x_Start + (x_Delta*i) + (x_Delta / 2);
							thread_array_Alt[i] = thread(Int_Rect, x_Mid, x_Delta, res_arr_Alt, i);
						}
					}
					else {
						for (int i = 0; i < length; i++) {
							x_Mid = x_Start + (x_Delta*i) + (x_Delta / 2);
							thread_array[i] = thread(Int_Rect, x_Mid, x_Delta, res_arr, i);
						}
						Flag = true;
					}
					time_pause = (double)(end_pause - start_pause);
				}
				if (Mode == 4 || Mode_Int_1 == 4 || Mode_Int_2 == 4) {
					std::cout << "Mode 4 - Integration with Trapezoidal rule case" << "\n";
					int start_pause = clock();
					if (acc_Mode == 1) {
						std::cout << "Enter Integration start point: ";
						std::cin >> x_Start;
						std::cin.ignore();
						std::cout << "Enter Integration end point: ";
						std::cin >> x_End;
						std::cin.ignore();
					}
					int end_pause = clock();
					x_Space = x_End - x_Start;
					x_Delta = x_Space / length;
					if (Flag == true) {
						for (int i = 0; i < length; i++) {
							x_1 = x_Start + x_Delta * i;
							x_2 = x_Start + x_Delta * (i + 1);
							thread_array_Alt[i] = thread(Int_Trap, x_1, x_2, x_Delta, res_arr_Alt, i);
						}
					}
					else {
						for (int i = 0; i < length; i++) {
							x_1 = x_Start + x_Delta * i;
							x_2 = x_Start + x_Delta * (i + 1);
							thread_array[i] = thread(Int_Trap, x_1, x_2, x_Delta, res_arr, i);
						}
						Flag = true;
					}
					time_pause = (double)(end_pause - start_pause);
				}
				if (Mode == 5 || Mode_Int_1 == 5 || Mode_Int_2 == 5) {
					std::cout << "Mode 5 - Integration with Simpson rule case" << "\n";
					int start_pause = clock();
					if (acc_Mode == 1) {
						std::cout << "Enter Integration start point: ";
						std::cin >> x_Start;
						std::cin.ignore();
						std::cout << "Enter Integration end point: ";
						std::cin >> x_End;
						std::cin.ignore();
					}
					int end_pause = clock();
					x_Space = x_End - x_Start;
					x_Delta = x_Space / length;
					if (Flag == true) {
						for (int i = 0; i < length; i++) {
							x_1 = x_Start + x_Delta * i;
							x_2 = x_Start + x_Delta * (i + 1);
							thread_array_Alt[i] = thread(Int_Sims, x_1, x_2, res_arr_Alt, i);
						}
					}
					else {
						for (int i = 0; i < length; i++) {
							x_1 = x_Start + x_Delta * i;
							x_2 = x_Start + x_Delta * (i + 1);
							thread_array[i] = thread(Int_Sims, x_1, x_2, res_arr, i);
						}
						Flag = true;
					}
					time_pause = (double)(end_pause - start_pause);
				}
				for (int i = 0; i < length; i++) {
					if (thread_array[i].joinable()) {
						thread_array[i].join();
					}
					if (acc_Mode == 2) {
						if (thread_array_Alt[i].joinable()) {
							thread_array_Alt[i].join();
						}
					}
				}
				if (Mode == 1) {
					Res = 0.0;
					for (int i = 0; i < length; i++) {
						Res = Res + res_arr[i];
					}
					Res = 4 * Res;
				}
				else if (Mode == 2) {
					Res = 1.0;
					for (int i = 0; i < length; i++) {
						Res = Res * res_arr[i];
					}
					Res = 2 * Res;
				}
				else if (Mode == 3 || Mode == 4 || Mode == 5) {
					if (acc_Mode == 2) {
						Res = 0.0;
						Result_Vrem = 0.0;
						for (int i = 0; i < length; i++) {
							Res = Res + res_arr[i];
							Result_Vrem = Result_Vrem + res_arr_Alt[i];
						}
					}
					else {
						Res = 0.0;
						for (int i = 0; i < length; i++) {
							Res = Res + res_arr[i];
						}
					}
				}
				std::cout << "Temporary Treads: " << length << "\n";
				if (acc_Mode == 1) {
					break;
				}
				else if (acc_Mode == 2 && (abs(Result_Vrem - Res) <= Accuracy) && (Mode == 1 || Mode == 2)) {
					break;
				}
				else if (acc_Mode == 2 && (abs(Result_Vrem - Res) <= Accuracy) && (Mode == 3 || Mode == 4 || Mode == 5)) {
					break;
				}
				Result_Vrem = Res;
				if (acc_Mode == 2) {
					length++;
				}
			}
			int end = clock();
			double time = (double)(end - start) - time_pause;
			std::cout << "\n";
			std::cout << ">>> Result = " << Res << "\n";
			std::cout << "\n";
			std::cout << "Processing time = " << time << " ms\n";
			std::cout << "---------------------" << "\n";
		}
	}
}