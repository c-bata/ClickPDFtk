#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


gboolean *StrString(const char *s1, const char *s2)
{
    s1 += strlen(s1)-strlen(s2);
    if(strcmp(s1, s2) == 0){ 
        return 1;
    }else{
        return 0;
    }
}

GtkWidget *startwindow;
GtkWidget *rotatewindow;	//cat_button_clickedのなかで書くとその中でしか使えない。グローバル変数にすること！
GtkWidget *catwindow;
GtkWidget *stampwindow;
GtkWidget *attachwindow;
GtkWidget *protectwindow;
GtkWidget *burstwindow;
GtkWidget *customwindow;
GtkWidget *acrodialog;

/*ここにwindowが表示中かどうかを判断する変数を書く*/
gboolean state_catwindow = FALSE;
gboolean state_rotatewindow = FALSE;
gboolean state_stampwindow = FALSE;
gboolean state_attachwindow = FALSE;
gboolean state_protectwindow = FALSE;
gboolean state_burstwindow = FALSE;
gboolean state_customwindow = FALSE;

gint filechooser = 0;
gint folderchooser = 0;

gint count_cat_infile = 0;

gchar *acrofile;

gboolean background = TRUE;

gboolean encryption = TRUE;
gboolean decryption = TRUE;
gboolean encrypt_option1 = TRUE;
gboolean encrypt_option2 = TRUE;

gboolean attach = TRUE;

gboolean cat_out = TRUE;
gboolean stamp_out = TRUE;
gboolean protect_out = TRUE;
gboolean attach_out = TRUE;
gboolean unattach_out = TRUE;
gboolean burst_out = TRUE;
gboolean rotate_out = TRUE;

gint *rotate_op1,*rotate_op2;

/* filechooserdialog **********************************************/


void
on_filechooserdialog_destroy           (GtkObject       *object,
                                        gpointer         user_data)
{
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_file_cancel_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "filechooserdialog");
	gtk_widget_destroy(fc);
}


void
on_file_open_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fc = lookup_widget(GTK_WIDGET(button),"filechooserdialog");

    switch(filechooser)
    {   
    case 1:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infilea_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 2:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infileb_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 3:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infilec_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 4:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_infile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 5:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_infile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 6:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_opinfile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 7:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_infile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 8:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_attachfile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 9:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(protectwindow,"protect_infile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 10:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(burstwindow,"burst_infile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 11:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(customwindow,"custom_infile_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    }   

    gtk_widget_destroy(fc);
}

/* folderchooserdialog **********************************************/

void
on_folderchooserdialog_destroy         (GtkObject       *object,
                                        gpointer         user_data)
{
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_folder_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "folderchooserdialog");
	gtk_widget_destroy(fc);
}


void
on_folder_open_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fc = lookup_widget(GTK_WIDGET(button),"folderchooserdialog");

    switch(folderchooser)
    {   
    case 1:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(catwindow,"cat_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 2:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 3:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 4:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 5:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(protectwindow,"protect_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 6:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(burstwindow,"burst_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 7:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(attachwindow,"unattach_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    case 8:
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(customwindow,"custom_outfolder_entry")),
                        gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)));
	break;
    }   

    gtk_widget_destroy(fc);

}

/* startwindow ***********************************************************************/
void
on_startwindow_show                    (GtkWidget       *widget,
                                        gpointer         user_data)
{
	startwindow=widget;
}


void
on_startwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data)
{
	gtk_widget_destroy(GTK_WIDGET(object));
	gtk_main_quit();
}


void
on_main_exit_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "startwindow");
	gtk_widget_destroy(fc);
	gtk_main_quit();
}

/* 各ボタンをクリックした時にそれぞれのwindowを開く関数 */

void
on_start_cat_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	if(state_catwindow == FALSE)
	{
		state_catwindow = TRUE;
		catwindow = create_catwindow ();
		gtk_widget_show (catwindow);
	}
}


void
on_start_burst_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	if(state_burstwindow == FALSE)
	{
		state_burstwindow = TRUE;
		burstwindow = create_burstwindow ();
		gtk_widget_show (burstwindow);
	}
}


void
on_start_rotate_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	if(state_rotatewindow == FALSE)
	{
		state_rotatewindow = TRUE;
		rotatewindow = create_rotatewindow ();
		gtk_widget_show (rotatewindow);
	}
}


void
on_start_protect_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	if(state_protectwindow == FALSE)
	{
		state_protectwindow = TRUE;
		protectwindow = create_protectwindow ();
		gtk_widget_show (protectwindow);
		gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_encrypt_frame")),TRUE);
	}
}


void
on_start_stamp_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	if(state_stampwindow == FALSE)
	{
		state_stampwindow = TRUE;
		stampwindow = create_stampwindow ();
		gtk_widget_show (stampwindow);
	}
}


void
on_start_attach_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	if(state_attachwindow == FALSE)
	{
		state_attachwindow = TRUE;
		attachwindow = create_attachwindow ();
		gtk_widget_show (attachwindow);
		gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "attach_frame")),TRUE);
	}
}



void
on_start_custom_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

	if(state_customwindow == FALSE)
	{
		state_customwindow = TRUE;
		customwindow = create_customwindow ();
		gtk_widget_show (customwindow);
	}
}


/* catwindow ***********************************************************************/

void
on_cat_fileadd_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	if(count_cat_infile < 3){
		count_cat_infile += 1;
	}else{
		return;
	}
	if(count_cat_infile == 1)
	{
		gtk_widget_set_visible(GTK_ENTRY(lookup_widget(catwindow , "cat_infileb_frame")),TRUE);
	}
	else if(count_cat_infile == 2)
	{
		gtk_widget_set_visible(GTK_ENTRY(lookup_widget(catwindow , "cat_infilec_frame")),TRUE);
	}
}

void
on_catwindow_destroy                   (GtkObject       *object,
                                        gpointer         user_data)
{
	count_cat_infile = 0;
	state_catwindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_cat_infilea_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=1;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);


	gtk_widget_show (filechooserdialog);
}


void
on_cat_infileb_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=2;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_cat_infilec_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=3;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_cat_outoption_radiobutton1_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(catwindow , "cat_output_frame")),FALSE);
	cat_out = TRUE;
}


void
on_cat_outoption_radiobutton2_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(catwindow , "cat_output_frame")),TRUE);
	cat_out = FALSE;
}


void
on_cat_outfolder_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=1;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}

void
on_cat_cancel_button_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	count_cat_infile = 0;
	state_catwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "catwindow");
	gtk_widget_destroy(fc);
}


void
on_cat_ok_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	state_catwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "catwindow");

	char command[256];
	gchar  *filenamea, *filenameb, *filenamec, *operation, *outfile;
	gchar *arange, *brange, *crange, *catopa, *catopb, *catopc;

	gint *catfa = gtk_combo_box_get_active(GTK_ENTRY(lookup_widget(catwindow,"cat_infilea_comboboxentry")));
	gint *catfb = gtk_combo_box_get_active(GTK_ENTRY(lookup_widget(catwindow,"cat_infileb_comboboxentry")));
	gint *catfc = gtk_combo_box_get_active(GTK_ENTRY(lookup_widget(catwindow,"cat_infilec_comboboxentry")));

	if(catfa == 0){
		catopa = "east";
	}else if(catfa == 1){
		catopa = "south";
	}else if(catfa == 2){
		catopa = "west";
	}else{
		catopa = "\0";
	}

	if(catfb == 0){
		catopb = "east";
	}else if(catfb == 1){
		catopb = "south";
	}else if(catfb == 2){
		catopb = "west";
	}else{
		catopb = "\0";
	}

	if(catfc == 0){
		catopc = "east";
	}else if(catfc == 1){
		catopc = "south";
	}else if(catfc == 2){
		catopc = "west";
	}else{
		catopc = "\0";
	}

	if(GTK_TOGGLE_BUTTON(lookup_widget(catwindow,"cat_option_checkbutton"))->active){
		operation = "shuffle";
	}else{
		operation = "cat";
	}

	if(cat_out != TRUE)
	{
		// g_build_filename関数で使うためには,const 修飾子をつける必要がある.
		const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_outfolder_entry")));
		const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_outfile_entry")));

		if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
		{
			outfile = "~/out.pdf";
		}
		else if (strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
		{
			const gchar *homepath = "~";
			outfile = g_build_filename(homepath, outfilename, NULL);
		}
		else if ((outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
		{
			const gchar *defaultname = "out.pdf";
			outfile = g_build_filename(outfolderpath, defaultname, NULL);
		}
		else
		{
			outfile = g_build_filename(outfolderpath, outfilename, NULL);
		}
	}
	else
	{
		outfile = "~/out.pdf";
	}

	if(StrString(outfile,".pdf")==FALSE){
		strcat(outfile,".pdf");
	}

	filenamea = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infilea_entry")));
	filenameb = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infileb_entry")));
	filenamec = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infilec_entry")));
	arange = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infilea_prange_entry")));
	brange = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infileb_prange_entry")));
	crange = gtk_entry_get_text(GTK_ENTRY(lookup_widget(catwindow,"cat_infilec_prange_entry")));

	// gtk_entry_get_text_length(...);っていう関数があるみたいだけど引数のentryの記述方法が分からない。

	if(strcmp(filenamea,"\0") != 0 && strcmp(filenameb,"\0") != 0 && strcmp(filenamec,"\0") != 0)
	{
		sprintf(command,"pdftk A=%s B=%s C=%s %s A%s%s B%s%s C%s%s output %s",filenamea,filenameb,filenamec,operation,arange,catopa,brange,catopb,crange,catopc,outfile);
	}
	else if(strcmp(filenamea,"\0") != 0 && strcmp(filenameb,"\0") != 0 && strcmp(filenamec,"\0") == 0)
	{
		sprintf(command,"pdftk A=%s B=%s %s A%s%s B%s%s output %s",filenamea,filenameb,operation,arange,catopa,brange,catopb,outfile);
	}
	else if(strcmp(filenamea,"\0") != 0 && strcmp(filenameb,"\0") == 0 && strcmp(filenamec,"\0") != 0)
	{
		sprintf(command,"pdftk A=%s C=%s %s A%s%s C%s%s output %s",filenamea,filenamec,operation,arange,catopa,crange,catopc,outfile);
	}
	else if(strcmp(filenamea,"\0") != 0 && strcmp(filenameb,"\0") == 0 && strcmp(filenamec,"\0") == 0)
	{
		sprintf(command,"pdftk A=%s %s A%s%s output %s",filenamea,operation,arange,catopa,outfile);
	}
	else if(strcmp(filenamea,"\0") == 0 && strcmp(filenameb,"\0") != 0 && strcmp(filenamec,"\0") != 0)
	{
		sprintf(command,"pdftk B=%s C=%s %s B%s%s C%s%s output %s",filenameb,filenamec,operation,brange,catopb,crange,catopc,outfile);
	}
	else if(strcmp(filenamea,"\0") == 0 && strcmp(filenameb,"\0") != 0 && strcmp(filenamec,"\0") == 0)
	{
		sprintf(command,"pdftk B=%s %s B%s%s output %s",filenameb,operation,brange,catopb,outfile);
	}
	else if(strcmp(filenamea,"\0") == 0 && strcmp(filenameb,"\0") == 0 && strcmp(filenamec,"\0") != 0)
	{
		sprintf(command,"pdftk C=%s %s C%s%s output %s",filenamec,operation,crange,catopc,outfile);
	}
	
	system(command);

	acrofile = outfile;
	/* acrodialog */
	acrodialog = create_acrodialog ();
	gtk_widget_show (acrodialog);

	count_cat_infile = 0;
	gtk_widget_destroy(fc);
}

/* stampwindow ***********************************************************************/

void
on_stampwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data)
{
	state_stampwindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_stamp_infile_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=5;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}



void
on_stamp_opback_radiobutton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	background = TRUE;
}


void
on_stamp_opstamp_radiobutton_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	background = FALSE;
}


void
on_stamp_opinfile_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=6;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_stamp_outfolder_button_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=3;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}


void
on_stamp_cancel_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	state_stampwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "stampwindow");
	gtk_widget_destroy(fc);
}


void
on_stamp_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(stampwindow , "stamp_output_frame")),FALSE);
	stamp_out = TRUE;
}


void
on_stamp_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(stampwindow , "stamp_output_frame")),TRUE);
	stamp_out = FALSE;
}


void
on_stamp_ok_button_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	state_stampwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "stampwindow");

	char command[256];
	gchar *filename, *opfilename, *options, *operation, *outfile;
	filename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_infile_entry")));
	opfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_opinfile_entry")));


	if(stamp_out != TRUE)
	{
		// g_build_filename関数で使うためには,const 修飾子をつける必要がある.
		const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_outfolder_entry")));
		const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(stampwindow,"stamp_outfile_entry")));

		if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
		{
			outfile = "~/out.pdf";
		}
		else if (strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
		{
			const gchar *homepath = "~";
			outfile = g_build_filename(homepath, outfilename, NULL);
		}
		else if ((outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
		{
			const gchar *defaultname = "out.pdf";
			outfile = g_build_filename(outfolderpath, defaultname, NULL);
		}
		else
		{
			outfile = g_build_filename(outfolderpath, outfilename, NULL);
		}
	}
	else
	{
		outfile = "~/out.pdf";
	}


	if(background == TRUE)
	{
		operation="background";
	}
	else
	{
		operation = "stamp";
	}

	if(StrString(outfile,".pdf")==FALSE){
		strcat(outfile,".pdf");
	}

	sprintf(command,"pdftk %s %s %s output %s",filename,operation,opfilename,outfile);
	system(command);

	acrofile = outfile;
	/* acrodialog */
	acrodialog = create_acrodialog ();
	gtk_widget_show (acrodialog);

	gtk_widget_destroy(fc);
}
/* protectwindow ***********************************************************************/


void
on_protectwindow_destroy               (GtkObject       *object,
                                        gpointer         user_data)
{
	state_protectwindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_protect_infile_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=9;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}

void
on_protect_lock_radiobutton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	encryption = TRUE;
	decryption = FALSE;
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_encrypt_frame")),TRUE);
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_decrypt_frame")),FALSE);
}


void
on_protect_unlock_radiobutton_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	encryption = FALSE;
	decryption = TRUE;
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_encrypt_frame")),FALSE);
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_decrypt_frame")),TRUE);
}


void
on_protect_outfolder_button_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=5;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}

void
on_protect_cancel_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	state_protectwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "protectwindow");
	gtk_widget_destroy(fc);
}


void
on_encrypt_radiobutton1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	encrypt_option1 = TRUE;
	encrypt_option2 = FALSE;
}


void
on_encrypt_radiobutton2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	encrypt_option1 = FALSE;
	encrypt_option2 = TRUE;
}


void
on_protect_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_output_frame")),FALSE);
	protect_out = TRUE;
}


void
on_protect_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(protectwindow , "protect_output_frame")),TRUE);
	protect_out = FALSE;
}


void
on_protect_ok_button_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	state_protectwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "protectwindow");

	char command[256];
	gchar *filename, *password, *operation, *outfile;
	gchar *options;
	filename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(protectwindow,"protect_infile_entry")));


        if(protect_out != TRUE)
        {
                // g_build_filename関数で使うためには,const 修飾子をつける必要がある.
                const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(protectwindow,"protect_outfolder_entry")));
                const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(protectwindow,"protect_outfile_entry")));


                if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
                {
			outfile = "~/out.pdf";
                }
                else if (strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
                {
                        const gchar *homepath = "~";
                        outfile = g_build_filename(homepath, outfilename, NULL);
                }
                else if ((outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
                {
                        const gchar *defaultname = "out.pdf";
                        outfile = g_build_filename(outfolderpath, defaultname, NULL);
                }
		else
		{
                        outfile = g_build_filename(outfolderpath, outfilename, NULL);
		}

        }
	else
	{
		outfile = "~/out.pdf";
        }

	if(StrString(outfile,".pdf")==FALSE){
		strcat(outfile,".pdf");
	}
	
	if(encryption == TRUE && encrypt_option1 == TRUE)
	{
		operation="owner_pw";
		password = gtk_entry_get_text(GTK_ENTRY(lookup_widget(protectwindow,"encrypt_entry")));
		sprintf(command,"pdftk %s output %s %s %s",filename,outfile,operation,password);
	}
	else if(encryption == TRUE && encrypt_option2 == TRUE){
		operation="user_pw";
		password = gtk_entry_get_text(GTK_ENTRY(lookup_widget(protectwindow,"encrypt_entry")));
		sprintf(command,"pdftk %s output %s %s %s",filename,outfile,operation,password);
	}
	else
	{
		operation = "input_pw";
		password = gtk_entry_get_text(GTK_ENTRY(lookup_widget(protectwindow,"decrypt_entry")));
		sprintf(command,"pdftk %s %s %s output %s",filename,operation,password,outfile);
	}

	system(command);

	acrofile = outfile;
	/* acrodialog */
	acrodialog = create_acrodialog ();
	gtk_widget_show (acrodialog);
	gtk_widget_destroy(fc);
}


/* acrodialog ***********************************************************************/

void
on_acrodialog_destroy                  (GtkObject       *object,
                                        gpointer         user_data)
{
	gtk_widget_destroy(GTK_WIDGET(object));
}

void
on_acroread_cancelbutton_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "acrodialog");
	gtk_widget_destroy(fc);
}


void
on_acroread_okbutton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "acrodialog");
	char command[256];
	sprintf(command,"acroread %s",acrofile);
	gtk_widget_destroy(fc);
	system(command);
}



/* attachwindow ***********************************************************************/

void
on_attachwindow_destroy                (GtkObject       *object,
                                        gpointer         user_data)
{
	state_attachwindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}

void
on_attach_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=7;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_attach_attachfile_button_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=8;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();
	gtk_widget_show (filechooserdialog);
}


void
on_attach_outfolder_button_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=4;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}


void
on_unattach_outfolder_button_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=7;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}

void
on_attachop_radiobutton1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "attach_frame")),TRUE);
	gtk_widget_set_visible(GTK_ENTRY(lookup_widget(attachwindow , "attach_output_frame")),TRUE);
	gtk_widget_set_visible(GTK_ENTRY(lookup_widget(attachwindow , "unattach_output_frame")),FALSE);

	attach = TRUE;
}


void
on_attachop_radiobutton2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "attach_frame")),FALSE);
	gtk_widget_set_visible(GTK_ENTRY(lookup_widget(attachwindow , "attach_output_frame")),FALSE);
	gtk_widget_set_visible(GTK_ENTRY(lookup_widget(attachwindow , "unattach_output_frame")),TRUE);

	attach = FALSE;
}

void
on_attach_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "attach_outoption_frame")),FALSE);
	attach_out = TRUE;
}


void
on_attach_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "attach_outoption_frame")),TRUE);
	attach_out = FALSE;
}

void
on_unattachfolder_radiobutton1_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "unattachfolder_hbox")),FALSE);
	unattach_out = TRUE;
}


void
on_unattachfolder_radiobutton2_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(attachwindow , "unattachfolder_hbox")),TRUE);
	unattach_out = FALSE;
}



void
on_attach_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	state_attachwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "attachwindow");
	gtk_widget_destroy(fc);
}



void
on_attach_ok_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	state_attachwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "attachwindow");

	char command[256];
	gchar *filename, *attachfile, *options, *operation, *outfile;
	filename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_infile_entry")));


	if(attach == TRUE)
	{
		operation="attach_files";
		attachfile = gtk_entry_get_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_attachfile_entry")));

		if(attach_out!=TRUE)
		{
			const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_outfolder_entry")));
			const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(attachwindow,"attach_outfile_entry")));

			if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
			{
				outfile = "~/out.pdf";
			}
			else if (strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
			{
				const gchar *homepath = "~";
				outfile = g_build_filename(homepath, outfilename, NULL);
			}
			else if (strcmp(outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
			{
				const gchar *defaultname = "out.pdf";
				outfile = g_build_filename(outfolderpath, defaultname, NULL);
			}
			else
			{
				outfile = g_build_filename(outfolderpath, outfilename, NULL);
			}
		}
		else
		{
			outfile = "~/out.pdf";
		}

		if(StrString(outfile,".pdf")==FALSE){
			strcat(outfile,".pdf");
		}

		sprintf(command,"pdftk %s %s %s output %s",filename,operation,attachfile,outfile);
	}
	else
	{
		operation="unpack_files";
		gchar *outfolder = gtk_entry_get_text(GTK_ENTRY(lookup_widget(attachwindow,"unattach_outfolder_entry")));

		if(unattach_out != TRUE && strcmp(outfolder,"\0") != 0){
			sprintf(command,"pdftk %s %s output %s",filename,operation,outfile);
		}else{
			sprintf(command,"pdftk %s %s output ~",filename,operation);
		}
	}

	system(command);
	//これはファイル添付するだけだからadobe readerいらない
	gtk_widget_destroy(fc);
}


/* burstwindow ***********************************************************************/


void
on_burstwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data)
{
	state_burstwindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_burst_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=10;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_burst_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(burstwindow , "burst_output_frame")),FALSE);
	burst_out = TRUE;
}


void
on_burst_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(burstwindow , "burst_output_frame")),TRUE);
	burst_out = FALSE;
}


void
on_burst_outfolder_button_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=6;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}


void
on_burst_cancel_button_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	state_burstwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "burstwindow");
	gtk_widget_destroy(fc);
}


void
on_burst_ok_button_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	state_burstwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "burstwindow");
	char command[256];
	gchar *filename,*outfile;

        if(burst_out != TRUE)
        {
                const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(burstwindow,"burst_outfolder_entry")));
                const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(burstwindow,"burst_outfile_entry")));

                if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
		{
			outfile = "~/out";
		}
                else if (strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
                {
                        const gchar *homepath = "~";
                        outfile = g_build_filename(homepath, outfilename, NULL);
                }
                else if ((outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
                {
                        const gchar *defaultname = "out";
                        outfile = g_build_filename(outfolderpath, defaultname, NULL);
		}
                else
		{
                        outfile = g_build_filename(outfolderpath, outfilename, NULL);
		}

	}
	else
	{
        	outfile = "~/out";
	}

	if(StrString(outfile,".pdf")==TRUE){
		char *a = outfile+strlen(outfile)-strlen(".pdf");
		*a = '\0';
	}

	filename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(burstwindow,"burst_infile_entry")));
	sprintf(command,"pdftk %s burst output %s_%%02d.pdf",filename,outfile);
	system(command);
	gtk_widget_destroy(fc);
}


/* rotatewindow ***********************************************************************/

void
on_rotatewindow_destroy                (GtkObject       *object,
                                        gpointer         user_data)
{
	state_rotatewindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}

void
on_rotate_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=4;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_rotate_outfolder_button_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=2;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}


void
on_rotate_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(rotatewindow , "rotate_output_frame")),FALSE);
	rotate_out = TRUE;
}


void
on_rotate_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	gtk_widget_set_sensitive(GTK_ENTRY(lookup_widget(rotatewindow , "rotate_output_frame")),TRUE);
	rotate_out = FALSE;
}

void
on_rotate_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	state_rotatewindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "rotatewindow");
	gtk_widget_destroy(fc);
}


void
on_rotate_ok_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	state_rotatewindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "rotatewindow");

	char command[256];
	gchar *filename,*outfile,*option;

	filename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_infile_entry")));


        if(rotate_out != TRUE)
        {
                const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_outfolder_entry")));
                const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_outfile_entry")));

                if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
		{
			outfile = "~/out.pdf";
		}
                else if (strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
                {
                        const gchar *homepath = "~";
                        outfile = g_build_filename(homepath, outfilename, NULL);
                }
                else if ((outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
                {
                        const gchar *defaultname = "out.pdf";
                        outfile = g_build_filename(outfolderpath, defaultname, NULL);
		}
                else
		{
                        outfile = g_build_filename(outfolderpath, outfilename, NULL);
		}

	}
	else
	{
        	outfile = "~/out.pdf";
	}

	if(StrString(outfile,".pdf")==FALSE){
		strcat(outfile,".pdf");
	}

	gint *rop1 = gtk_combo_box_get_active(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_oppage_comboboxentry")));
	gint *rop2 = gtk_combo_box_get_active(GTK_ENTRY(lookup_widget(rotatewindow,"rotate_opangle_comboboxentry")));

	if(rop1 == 0 && rop2 == 0){
		option = "A1-endright";
	}else if(rop1 == 0 && rop2 == 1){
		option = "Adown";
	}else if(rop1 == 0 && rop2 == 2){
		option = "Aleft";
	}else if(rop1 == 1 && rop2 == 0){
		option = "Aoddright Aeven";
	}else if(rop1 == 1 && rop2 == 1){
		option = "Aodddown Aeven";
	}else if(rop1 == 1 && rop2 == 2){
		option = "Aoddleft Aeven";
	}else if(rop1 == 2 && rop2 == 0){
		option = "Aodd Aevenright";
	}else if(rop1 == 2 && rop2 == 1){
		option = "Aodd Aevendown";
	}else if(rop1 == 2 && rop2 == 2){
		option = "Aodd Aevenleft";
	}else{
		option = "A";
	}

	sprintf(command,"pdftk A=%s shuffle %s output %s",filename,option,outfile);
	
	system(command);
	acrofile = outfile;
	/* acrodialog */
	acrodialog = create_acrodialog ();
	gtk_widget_show (acrodialog);

	gtk_widget_destroy(fc);
}

/* customwindow ***********************************************************************/

void
on_customwindow_destroy                (GtkObject       *object,
                                        gpointer         user_data)
{
	state_customwindow = FALSE;
	gtk_widget_destroy(GTK_WIDGET(object));
}


void
on_custom_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	filechooser=11;
	GtkWidget *filechooserdialog;
	filechooserdialog = create_filechooserdialog ();

	//ここにPDFファイルのフィルタ設定とすべてのファイルのフィルタ設定を追記
	GtkFileFilter *filter;
	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "PDF File");
	gtk_file_filter_add_pattern(filter,"*.pdf");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	filter = gtk_file_filter_new ();
	gtk_file_filter_set_name (filter, "All Files");
	gtk_file_filter_add_pattern(filter,"*");
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (filechooserdialog), filter);

	gtk_widget_show (filechooserdialog);
}


void
on_custom_outfolder_button_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	folderchooser=8;
	GtkWidget *folderchooserdialog;
	folderchooserdialog = create_folderchooserdialog ();
	gtk_widget_show (folderchooserdialog);
}


void
on_custom_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	state_customwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "customwindow");
	gtk_widget_destroy(fc);
}


void
on_custom_ok_button_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	state_customwindow = FALSE;
	GtkWidget *fc = lookup_widget(GTK_WIDGET(button), "customwindow");

	char command[256];
	gchar *filename,*outfile,*operation;

	filename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(customwindow,"custom_infile_entry")));
	operation = gtk_entry_get_text(GTK_ENTRY(lookup_widget(customwindow,"custom_operation_entry")));

	const gchar *outfolderpath = gtk_entry_get_text(GTK_ENTRY(lookup_widget(customwindow,"custom_outfolder_entry")));
	const gchar *outfilename = gtk_entry_get_text(GTK_ENTRY(lookup_widget(customwindow,"custom_outfile_entry")));

        if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") == 0)
	{
		outfile = "~/output";
	}
	else if(strcmp(outfolderpath,"\0") == 0 && strcmp(outfilename,"\0") != 0)
	{
		const gchar *homepath = "~";
		outfile = g_build_filename(homepath, outfilename, NULL);
	}
        else if ((outfolderpath,"\0") != 0 && strcmp(outfilename,"\0") == 0)
        {
                const gchar *defaultname = "output";
                outfile = g_build_filename(outfolderpath, defaultname, NULL);
	}
	else
	{
		outfile = g_build_filename(outfolderpath, outfilename, NULL);
	}

	sprintf(command,"pdftk %s %s output %s",filename,operation,outfile);
	
	system(command);
	gtk_widget_destroy(fc);
}

