using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Human : Character  //human 클래스는 character 클래스를 상속받았다.
    {
     int maxMp = 200;
     int mp = 100;


        public Human() : base()
        {
            Generate_Stat();  //
            TestPrintStatus();
        }

        public Human(string newname2) : base()
        {
            Generate_Stat();  //
            TestPrintStatus();
        }


        public override void Generate_Stat()
        {
            base.Generate_Stat(); //Character의 Genarateed_stat 함수 실행
            maxMp = rand.Next() % 100; //추가한 변수만 추가로 처리
            mp = maxMp;
        }

        public override void TestPrintStatus()
        {
            Console.WriteLine("┏━━━━━━━━━━━━━━━━━━━━━━┓");
            Console.WriteLine($"┃이름\t:\t{name}");
            Console.WriteLine($"┃HP\t:\t{hp}/{maxHp}");
            Console.WriteLine($"┃MP\t:\t{mp}/{maxMp}");
            Console.WriteLine($"┃힘\t:\t{strength}");
            Console.WriteLine($"┃인지\t:\t{precision}");
            Console.WriteLine($"┃인내\t:\t{endurance}");
            Console.WriteLine($"┃매력\t:\t{charisma}");
            Console.WriteLine($"┃지능\t:\t{intelligence}");
            Console.WriteLine($"┃민첩\t:\t{agility}");
            Console.WriteLine($"┃행운\t:\t{luck}");
            Console.WriteLine("┗━━━━━━━━━━━━━━━━━━━━━━┛");
        }


        public override void Attack(Character target)
        {
            int damage = strength;

            //rand.NextDouble(); //0.1~1.0
            if (rand.NextDouble() < 0.3f)
            {
                damage *= 2; //damage=damage*2
                Console.WriteLine("*크리티컬 히트");
            }

            target.TakeDamage(damage);


            Console.WriteLine($"1*{name}이/가 {target.Name}에게 공격합니다.(공격력 : {damage})");


        }
    }
}
