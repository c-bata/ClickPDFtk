#include <gtk/gtk.h>


void
on_startwindow_show                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_startwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data);

void
on_start_cat_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_burst_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_rotate_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_protect_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_stamp_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_attach_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_metadata_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_custom_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_catwindow_show                      (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_catwindow_destroy                   (GtkObject       *object,
                                        gpointer         user_data);

void
on_cat_infilea_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infileb_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilec_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infileachooserdialog_destroy    (GtkObject       *object,
                                        gpointer         user_data);

void
on_cat_infilea_cancel_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilea_ok_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilebchooserdialog_destroy    (GtkObject       *object,
                                        gpointer         user_data);

void
on_cat_infileb_cancel_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infileb_ok_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilecchooserdialog_destroy    (GtkObject       *object,
                                        gpointer         user_data);

void
on_cat_infilec_cancel_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilec_ok_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_outfilechooserdialog_destroy    (GtkObject       *object,
                                        gpointer         user_data);

void
on_cat_outfile_cancel_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_outfile_ok_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_outfolder_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_cancel_button_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_ok_button_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infileb_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilec_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_fileadd_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_outfolder_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_ok_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_infilechooserdialog_destroy  (GtkObject       *object,
                                        gpointer         user_data);

void
on_rotate_infile_cancel_button_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_infile_ok_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_outfilechooserdialog_destroy (GtkObject       *object,
                                        gpointer         user_data);

void
on_rotate_outfile_cancel_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_outfile_ok_button_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotatewindow_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_stampwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data);

void
on_stamp_infile_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_opinfile_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_outfolder_button_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_cancel_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_ok_button_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_attachfilechooserdialog_destroy
                                        (GtkObject       *object,
                                        gpointer         user_data);

void
on_stamp_outfile_cancel_button_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_attachfile_ok_button_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_attachfile_cancel_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_stamp_infile_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_attach_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_attach_attachfile_button_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_attaachfolder_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_attach_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_attach_ok_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_attachwindow_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_protectwindow_destroy               (GtkObject       *object,
                                        gpointer         user_data);

void
on_protect_infile_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_protect_outfolder_button_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_protect_cancel_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_protect_ok_button_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_protect_opinfile_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_filechooserdialog_destroy           (GtkObject       *object,
                                        gpointer         user_data);

void
on_file_cancel_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_file_open_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_folderchooserdialog_destroy         (GtkObject       *object,
                                        gpointer         user_data);

void
on_folder_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_folder_open_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilea_checkbutton_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cat_infileb_checkbutton_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cat_infilec_checkbutton_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cat_option_checkbutton_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_stamp_opback_radiobutton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_stamp_opstamp_radiobutton_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_protect_lock_radiobutton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_protect_unlock_radiobutton_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_encrypt_radiobutton1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_encrypt_radiobutton2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_attachop_radiobutton1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_attachop_radiobutton2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_attachfolder_radiobutton1_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_attachfolder_radiobutton2_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_protect_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_protect_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cat_outoption_radiobutton1_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cat_outoption_radiobutton2_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rotate_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rotate_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_stamp_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_stamp_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rotate_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_burst_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_burst_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_burst_outfolder_button_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_burst_cancel_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_burst_ok_button_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_burstwindow_destroy                 (GtkObject       *object,
                                        gpointer         user_data);

void
on_burst_infile_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_acroread_cancelbutton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_acroread_okbutton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_acrodialog_destroy                  (GtkObject       *object,
                                        gpointer         user_data);

void
on_attach_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_attach_outoption_radiobutton2_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_unattachfolder_radiobutton1_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_unattachfolder_radiobutton2_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_attach_outfolder_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_unattach_outfolder_button_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilea_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infileb_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_cat_infilec_button_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_rotate_oppage_comboboxentry_changed (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_rotate_opangle_comboboxentry_changed
                                        (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_main_exit_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_start_custom_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_main_exit_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_customwindow_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_custom_infile_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_custom_outoption_radiobutton1_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_custom_output_radiobutton2_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_custom_outfolder_button_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_custom_cancel_button_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_custom_ok_button_clicked            (GtkButton       *button,
                                        gpointer         user_data);
