#include <stdlib.h>
#include <gtk/gtk.h>  
#include <stdio.h>  
#include <string.h>  
#include "task2.h"

char * (* func) (char * , int ) ; 

static  int majorFunction(GtkWidget * GtkButton , GtkWidget * widgetArray[]){
	const  gchar * text1 = gtk_entry_get_text(GTK_ENTRY(widgetArray[1]));	
	const  gchar * text2 = gtk_entry_get_text(GTK_ENTRY(widgetArray[3]));	
	int    wordLength    = atoi(text2);
	char * result = func((char *)text1, wordLength);
	gtk_entry_set_text(GTK_ENTRY(widgetArray[2]),result);
}

static  int RadioChange1(GtkWidget * radio , double (* function)(char *) ){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
		func = algorithm1; 
	}
}
static  int  RadioChange2(GtkWidget * radio , double (* function)(char *) ){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
		func = algorithm2;
	}
}
static  int  RadioChange3(GtkWidget * radio , double (* function)(char *) ){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
		func = algorithm3;
	}
}
static  int  RadioChange4(GtkWidget * radio , double (* function)(char *) ){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
		func = algorithm4;
	}
}
static  int  BinaryToDecimal(GtkButton * botton, GtkWidget* widgetArray[])  {
	/*
	 * const  gchar * text = gtk_entry_get_text(GTK_ENTRY(widgetArray[1]));	
	 * double  sum  = (*func)((char *) text);
	 * gchar  decimal[100] ;
	 * const gchar * string = decimal ;
	 * sprintf(decimal , "%lf", sum );
	 * gtk_entry_set_text(GTK_ENTRY(widgetArray[2]),string);
	 */
}
int main(int argc,char *argv[])  
{  
	//1.gtk环境初始化  
	gtk_init(&argc, &argv);  

	func = algorithm1;    
	//2.创建一个窗口 设置窗口的信息
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);   

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_window_set_default_size(GTK_WINDOW(window), 1100, 900); 

	gtk_window_set_title(GTK_WINDOW(window) ,"进制转化程序");
	//3.创建一个fixed布局 并加入窗口布局中去
	GtkWidget * fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window) , fixed);
	//4.创建 按钮及文本框等控件
	GtkWidget * botton1 = gtk_button_new_with_label("转化");
	GtkWidget * entry1 = gtk_entry_new();  
	GtkWidget * entry2 = gtk_entry_new();  
	GtkWidget * entry3 = gtk_entry_new();  
	GtkWidget * label1 = gtk_label_new("请输入要转化的二进制真值（定点整数或者定点小数,正数前面加正号,负数前面加负号:)");
	GtkWidget * lable2 = gtk_label_new("请输入转化的编码类型");
	GtkWidget * lable3 = gtk_label_new("请输入机器字长:");
	GtkWidget * radio1 = gtk_radio_button_new_with_label(NULL, "原码");
	GSList    * group1 = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio1));
	GtkWidget * radio2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "补码");
	GtkWidget * radio3 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "反码");
	GtkWidget * radio4 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "移（增）码");
	GtkWidget * function1[3] ;
	function1[0] = botton1 ;
	function1[1] = entry1  ;
	function1[2] = entry2  ;
	function1[3] = entry3  ;

	//5.加入到固定布局中去，以及设置按钮，文本框等信息
	gtk_fixed_put(GTK_FIXED(fixed), entry1, 100, 100 );
	gtk_fixed_put(GTK_FIXED(fixed), botton1, 500, 100);
	gtk_fixed_put(GTK_FIXED(fixed), label1, 150, 50);
	gtk_fixed_put(GTK_FIXED(fixed), entry2, 700, 100);
	gtk_fixed_put(GTK_FIXED(fixed), lable3, 500, 200);
	gtk_fixed_put(GTK_FIXED(fixed), entry3, 700, 200);
	gtk_fixed_put(GTK_FIXED(fixed), radio1, 100, 200);
	gtk_fixed_put(GTK_FIXED(fixed), radio2, 200, 200);
	gtk_fixed_put(GTK_FIXED(fixed), radio3, 300, 200);
	gtk_fixed_put(GTK_FIXED(fixed), radio4, 400, 200); 	

	gtk_widget_set_size_request(botton1,100, 50);
	gtk_widget_set_size_request(entry1, 100, 50);
	gtk_widget_set_size_request(entry2, 200, 50);
	// gtk_widget_set_size_request(entry3, 100, 50);

	//设置行编辑的内容  
	gtk_entry_set_text(GTK_ENTRY(entry1), "-1111");  
	gtk_entry_set_text(GTK_ENTRY(entry3), "16");  

	//设置行编辑不允许编辑，只能显示用  
	gtk_editable_set_editable(GTK_EDITABLE(entry1), TRUE);  
	gtk_editable_set_editable(GTK_EDITABLE(entry2), FALSE);  

	//设置回调函数
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(botton1, "clicked", G_CALLBACK(majorFunction),function1);
	g_signal_connect(radio1, "toggled", G_CALLBACK(RadioChange1),func);
	g_signal_connect(radio2, "toggled", G_CALLBACK(RadioChange2),func);
	g_signal_connect(radio3, "toggled", G_CALLBACK(RadioChange3),func);
	g_signal_connect(radio4, "toggled", G_CALLBACK(RadioChange4),func);

	//7.显示所有控件  
	gtk_widget_show_all(window);  

	//8.主事件循环  
	gtk_main();  

	return 0;  
}  
