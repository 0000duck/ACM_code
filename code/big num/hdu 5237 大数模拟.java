package acm;

import java.util.Base64;
import java.util.Scanner;
public class HDU5237 {//����ʱ������ĳ�Main
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);  
        int cas=sc.nextInt();
        for (int k=1;k<=cas;k++)
        {
        	int cnt = sc.nextInt();  
        	String str = sc.next();  
        	byte tt[] = str.getBytes(); //ת��byte��  
        	for (int i=0;i<cnt;i++)
        	{
        		tt = Base64.getEncoder().encode(tt); //����  
        		//Base64.getDecoder().decode(tt); //����  
        	}//coder ������  
        	System.out.println("Case #" + k + ": " + (new String(tt)));  
        	//���ʱ�ǵ�ת��ԭ������
        }
	}
}
