class Truck {

private:
	float weight;
	float height;
	float tire_size;

public:
	Truck() {
		weight = 100;
		height = 15;
		tire_size = 5;
	}

	void draw_truck();
	void truck_move();
	void truck_tilt();

}




class Car {

private:
	float length;
	float width;
	float resistance_factor; // must be 1-5

public:
	Car() {
		length = 15;
		width = 5;
		resistance = 3;
	}

	void draw_car();
}