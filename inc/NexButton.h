#ifndef __NEXBUTTON_H__
#define __NEXBUTTON_H__

#include "NexTouch.h"
#include "NexHardware.h"
#include "my_types.h"

unsigned int NexButton_getText(struct NexObject *button, char *buffer, unsigned int len);

/**
     * Set text attribute of component.
     *
     * @param buffer - text buffer terminated with '\0'. 
     * @return true if success, false for failure. 
     */
unsigned short NexButton_setText(struct NexObject *button, const char *buffer);

/**
     * Get bco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_background_color_bco(struct NexObject *button, unsigned long *number);

/**
     * Set bco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_background_color_bco(struct NexObject *button, unsigned long number);

/**
     * Get bco2 attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_press_background_color_bco2(struct NexObject *button, unsigned long *number);

/**
     * Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_press_background_color_bco2(struct NexObject *button, unsigned long number);

/**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_font_color_pco(struct NexObject *button, unsigned long *number);

/**
     * Set pco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_font_color_pco(struct NexObject *button, unsigned long number);

/**
     * Get pco2 attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_press_font_color_pco2(struct NexObject *button, unsigned long *number);

/**
     * Set pco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_press_font_color_pco2(struct NexObject *button, unsigned long number);

/**
     * Get xcen attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_place_xcen(struct NexObject *button, unsigned long *number);

/**
     * Set xcen attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_place_xcen(struct NexObject *button, unsigned long number);

/**
     * Get ycen attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_place_ycen(struct NexObject *button, unsigned long *number);

/**
     * Set ycen attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_place_ycen(struct NexObject *button, unsigned long number);

/**
     * Get font attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_getFont(struct NexObject *button, unsigned long *number);

/**
     * Set font attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_setFont(struct NexObject *button, unsigned long number);

/**
     * Get picc attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_background_cropi_picc(struct NexObject *button, unsigned long *number);

/**
     * Set picc attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_background_crop_picc(struct NexObject *button, unsigned long number);

/**
     * Get picc2 attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_press_background_crop_picc2(struct NexObject *button, unsigned long *number);

/**
     * Set picc2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_press_background_crop_picc2(struct NexObject *button, unsigned long number);

/**
     * Get pic attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_background_image_pic(struct NexObject *button, unsigned long *number);

/**
     * Set pic attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_background_image_pic(struct NexObject *button, unsigned long number);

/**
     * Get pic2 attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
unsigned long NexButton_Get_press_background_image_pic2(struct NexObject *button, unsigned long *number);

/**
     * Set pic2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
unsigned short NexButton_Set_press_background_image_pic2(struct NexObject *button, unsigned long number);

#endif /* #ifndef __NEXBUTTON_H__ */
