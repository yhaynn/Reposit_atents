﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//추가적인 기능을 사용할 것인지 표시하는 것


// namespace : 이름이 겹치는것을 방지하기 위해 구분지어놓은 용도
namespace ConsoleApp1
{
    //internal: 같은 어셈블리안에서는 public 다른 어셈블러라면 private

    //접근제한자(Access Modifier) 
    // public : 누구든지 접근할수 있다  ***
    // private : 자기 자신이나 같은 멤버만 접근할 수 있다 ***
    // protected : 자기과 자신을 상속받은 자식만 접근할 수 있다. ***
    // internal : 같은 어셈블리 안에서는 public 다른 어셈블리면 private




    public class Character // Character 라는 클래스를 public으로 선언한다.(틀을 만들었다) rpg 게임을 예시로 보자(폴아웃?)

    //class 사용법은 사용할 프로젝트에서 
    {
        //멤버변수 ->데이터
        protected int hp; //C#에서는 기본적으론 private다. 따라서 hp만 public int hp 하면 program 프로젝트에서 사용가능하다
        protected int maxHp; //protected로 상속받는 자식 프로젝트가 접근 가능해짐
        protected int stamina;
        protected int strength;
        protected int intelligence;
        protected int agility;
        
        protected string name;
        protected int mp;
        protected int maxMp;

        const int DefenseCount = 3;
        int remainsDefenseCount = 0;

        public string Name => name;

        //배열 : 같은 종유(데이터타입)의 데이터를 한번에 여러개 가지는 유형의 변수
        // int[] intArray; //인티저를 여러개 가질수 있는 배열
        // intArray = new int[5]; //인티저를 5개 가질 수 있도록 생성


        //string[] nameArray = { "플레이어1", "플레이어2", "플레이어3", "플레이어4", "플레이어5" }; //nameArray에 기본값 설정(선언과 동시에 할당)
        protected Random rand;


        public int HP  //HP는 프로퍼티 라고 한다
        {
            get
            {
                return hp; //이 프로퍼티를 읽을때 호출되는 부분. get만 만들면 읽기 전용

            }

            set
            {
                hp = value; // 이 프로퍼티에 값을 넣을때 호출되는 부분. set 앞에 private를 입력시 나만 쓰는것이 가능.

                if (hp > maxHp)
                {
                    hp = maxHp;
                }

                
                else if (hp <= 0)
                {
                    Console.WriteLine($"{name}이/가 사망하였습니다"); //사망 처리 함수 호출

                }
                
            }
        }

        public int MP
        {
            get
            {
                return mp; 

            }

            set
            {
                mp = value; 

                if (mp > maxMp)
                {
                    mp = maxMp;
                }


                else if (mp <= 0)
                {
                    Console.WriteLine($"스킬을 사용할 수 없습니다."); 

                }

            }
        }


        public Character()
        {
            //Console.WriteLine($"{name}");
            rand = new Random(DateTime.Now.Millisecond);
            int randomNumber = rand.Next();
            //randomNumber %= 5;                  //randomNumber = randomNumber % 5;
            //name = nameArray[randomNumber];    //랜덤, 모듈레이터

            Random rand2 = new Random();
            rand2 = new Random();
            Generate_Stat();  //스테이터스 생성
            TestPrintStatus();  //스테이터스 출력

            
        }

        public Character(string newName2)
        {

            rand = new Random(DateTime.Now.Millisecond);
            //Console.WriteLine($"{newName2}");
            name = newName2;

            //Generate_Stat();
            //TestPrintStatus();
        }


        public virtual void Generate_Stat()
        {
            //hp 랜덤
            maxHp = rand.Next(100, 201);
            hp = maxHp;

            //stat 랜덤

            strength = rand.Next(20) + 1;
            intelligence = rand.Next(20) + 1;
            strength = rand.Next(20) + 1;
            stamina = rand.Next(20) + 1;



        }  

                


        public virtual void Attack(Character target)
        {
            int damage = strength;

            if (rand.NextDouble() < 0.3f)           //크리티컬..이 확률이라면 크리티컬이 발동한다. 굳이 else if 필요 없는 상황
            {
                damage *= 2; 
                Console.WriteLine($"*크리티컬 히트");
            }

          
               
                target.TakeDamage(damage);  ////타켓 확인 잘하자
                Console.WriteLine($"[{name}]이/가 [{target.Name}]에게 공격을 합니다.(공격력 : {damage})\n[5{target.Name}]은/는 {damage}만큼 피해를 입었습니다.");
            

            
        }

        public virtual void Defense()
        {
            Console.WriteLine($"3턴간 받는 데미지 반감");
            remainsDefenseCount += DefenseCount;
        }
        //public virtual void Attack(Character target)
        //{
        //    int damage = strength;
        //    Console.WriteLine($"1{name}이/가 {target.Name}에게 공격합니다.(공격력 : {damage})");
        //    target.TakeDamage(damage);

        //}



        public virtual void TakeDamage(int damage)
        {
            HP -= damage;
            //Console.WriteLine($"2[{name}]은/는 {damage}만큼의 피해를 입었습니다.");
            
        }
        
        public virtual void TestPrintStatus()  //Char 스텟창
        {
            Console.WriteLine("┏━━━━━━━━━━━━━━━━━━━━━━┓");
            Console.WriteLine($"┃이름\t:\t{name}");
            Console.WriteLine($"┃HP\t:\t{hp}/{maxHp}");
            Console.WriteLine($"┃힘\t:\t{strength}");
            Console.WriteLine("┗━━━━━━━━━━━━━━━━━━━━━━┛");

        }



    }
}