using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Orc : Character  //오크 클래스는 character 클래스를 상속받았다.
    {
        int maxMp = 200;
        int mp = 100;

        //오크 전용 스텟-공격에 대한 상쇄

        public Orc(string newName2) : base(newName2)
        {
            //Generate_Stat();  
            //TestPrintStatus();
        }

        

        public override void Generate_Stat()
        {
            base.Generate_Stat(); //Character의 Genarate_stat 함수 실행
            maxMp = rand.Next() % 100; //추가한 변수만 추가로 처리
            mp = maxMp;

            endurance = rand.Next(30) + 1;
        }



        //public override void Attack(Character target)
        //{
        //    int damage = strength;

        //    //rand.NextDouble(); //0.1~1.0
        //    if (rand.NextDouble() < 0.3f)
        //    {

        //        damage *= 2; //damage=damage*2
        //        Console.WriteLine("*크리티컬 히트");
        //    }
        //        Console.WriteLine($"22222{name}이/가 {target.Name}에게 공격합니다.(공격력 : {damage})");
        //        target.TakeDamage(damage);

        //}

        public override void TakeDamage(int damage)  //일정 확률로 오크는 인내수치 만큼 데미지를 감소 시킨다.
        {
            //int strenght=damage;

            if (rand.NextDouble() < 0.3f)
            
                if (endurance > damage)
                {
                    HP -= damage / 2;
                    Console.WriteLine($"[{Name}]은 공격을 버텼습니다. {damage / 2}만큼 피해를 감소시켰습니다.");
                }
                else 
                {
                    HP -= damage;
                    Console.WriteLine($"2[{Name}]은/는 {damage}만큼의 피해를 입었습니다.");

                }
            




        }
        public override void TestPrintStatus()
        {
            Console.WriteLine("┏━━━━━━━━━━━━━━━━━━━━━━┓");
            Console.WriteLine($"┃이름\t:\t{name}");
            Console.WriteLine($"┃HP\t:\t{hp}/{maxHp}");
            Console.WriteLine($"┃MP\t:\t{mp}/{maxMp}");
            Console.WriteLine($"┃힘\t:\t{strength}");
            Console.WriteLine($"┃인내\t:\t{endurance}");
            Console.WriteLine("┗━━━━━━━━━━━━━━━━━━━━━━┛");
        }
    }
}