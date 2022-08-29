#include <iostream>

using namespace std;  //이건 대체 무엇이더나.
//다자간 개발이 경우 이름 충돌이 생긴다. 그걸 해결하기 위한 뭐시기


namespace LG {
	class Math {
	public: 
		int _value;
	};
}

namespace Samsung {
	class Math {
	public:
		int _value;
	};
}

int main() {


	return 0;
}


/*#include <iostream>

//using namespace std;

namespace LG {
   class Math {
   public:
      int _value;
   };
}

namespace Samsung {
   class Math {
   public:
      int _value;
   };
}

int main() {
   LG::Math a;

   using namespace Samsung;
   Math b;

   std::cout << "monster" << endl;


   return 0;
}*/