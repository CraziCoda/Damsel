namespace Damsel {
	class _declspec(dllimport)  Application
	{
	public:
		Application();
		virtual ~Application();
		void setup();
	};
}

int main() {
	Damsel::Application car;
	
	car.setup();

	return 0;
}