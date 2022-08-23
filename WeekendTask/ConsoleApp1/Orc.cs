using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Orc : Character  //오크 클래스는 character 클래스를 상속받았다.
    {
        
        int endurance;  ///const int endurance = 100하면 endurance는 100에 고정된 상수임을 선언한다. 바뀌지 않는다.
        //오크 전용 스텟-공격에 대한 상쇄

        public Orc(string newName) : base(newName)
        {
            Generate_Stat();
            TestPrintStatus();
        }
        //public Orc()
        //{
        //    //이게 없으면 public Orc(string newName) : base(newName)만 존재
        //    //자동으로 상속받은 부모의 생성자도 실행
        //}

        
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

        public override void TakeDamage(int damage)  //일정 확률로 오크는 인내수치가 데미지보다 높으면 데미지를 감소 시킨다.
        {
            int strenght = damage;

            if (rand.NextDouble() < 0.3f)
            {
                ///여기서 괄호 생략이 돼있음. 조건 통과를 못해서 공격이 안들어감}
                if (endurance > damage)
                {
                    HP -= damage / 2;
                    Console.WriteLine($"[{Name}]은 공격을 버텼습니다. {damage / 2}만큼 피해를 감소시켰습니다.");
                }

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