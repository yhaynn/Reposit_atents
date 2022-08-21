﻿using System;
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
            //Generate_Stat();  //
            //TestPrintStatus();
        }

        


        public override void Generate_Stat()
        {
            base.Generate_Stat(); //Character의 Genarateed_stat 함수 실행
            maxMp = rand.Next() % 100; //추가한 변수만 추가로 처리
            mp = maxMp;

            agility = rand.Next(20) + 1;
        }



        public override void Attack(Character target)
        {
            

            Console.WriteLine("1)공격\t2)스킬\t3)도주\t");
            String SelectNum=Console.ReadLine();
            int num = int.Parse(SelectNum);
            
            switch (num)
            {
                case 1:
                    {
                        Console.WriteLine($"\n[{name}]이/가 공격을 실행합니다.\n");

                        int damage = strength;


                        //rand.NextDouble(); //0.1~1.0


                        if (rand.NextDouble() < 0.3f)
                        {
                            damage *= 2; //damage=damage*2
                            Console.WriteLine($"*크리티컬 히트");
                            //target.TakeDamage(damage);
                        }

                        else
                        {
                            HP -= damage;
                        }
                        Console.WriteLine($"[{name}]이/가 [{target.Name}]에게 공격을 합니다.(공격력 : {damage})\n[{target.Name}]은/는 {damage}만큼 피해를 입었습니다.");

                        target.TakeDamage(damage);

                        break;
                    }
                case 2:
                    {
                        Console.WriteLine($"\n[{name}]이/가 스킬을 사용합니다.\n");
                        Human_Skill();
                        break;
                    }
                case 3:
                    {
                        Console.WriteLine($"\n[{name}]이/가 도주합니다...\n");
                        Human_dodge();
                        break;
                    }
            }

        }


        public override void TakeDamage(int damage) 
        {
            
            if (rand.NextDouble() < 0.3f)

                if (agility > damage)
                {
                    HP -= damage /4;
                    Console.WriteLine($"11[{name}]은 공격을 회피하여 {damage /4}만큼의 피해로 빗맞았습니다.");
                
                    
                }

                else
                {
                    HP -= damage;
                    Console.WriteLine($"1[{name}]은/는 {damage}만큼의 피해를 입었습니다.");
                }

        }



        public override void TestPrintStatus()
        {
            Console.WriteLine("┏━━━━━━━━━━━━━━━━━━━━━━┓");
            Console.WriteLine($"┃이름\t:\t{name}");
            Console.WriteLine($"┃HP\t:\t{hp}/{maxHp}");
            Console.WriteLine($"┃MP\t:\t{mp}/{maxMp}");
            Console.WriteLine($"┃힘\t:\t{strength}");
            Console.WriteLine($"┃민첩\t:\t{agility}");
            Console.WriteLine("┗━━━━━━━━━━━━━━━━━━━━━━┛");
        }

        public void Human_Skill()
        {
            if (mp > 5)
            {
                Console.WriteLine($"{name}의 hp를 회복합니다.");
                HP += 20;
                mp -= 5;
            }

            else if(mp < 4)
            {
                Console.WriteLine("스킬을 사용할 수 없습니다.");
            }
        }

        public void Human_dodge()
        {
            Console.ReadKey();
            Environment.Exit(0);
        }
    }
}
