/*
  preface
*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

/*
 init and close section 
*/

static int __init initialization_function(void)
{

  //init code


}
module_init (initalization_function);  //module_init is a macro which used to 
                                       //location of the kernel init function
                                       //where it is? if not define this macro
                                       //than the init function would never be called

/* every module can registered as some device and some filesystem and so on, For each 
role item there is a kernel function supoortted to register actions, so the function arg 
which passed to kernel dual regsiter function will be some data structure, It often 
content a pointer which point to module, than the funcitons in the module will be call
in the right time

   BTW, most of register function named begin with "register_"

*/




/* cleanup function */

static void __exit cleanup_function(void)
{
  //cleanup code

}

module_exit(cleanup_function);


/* error processing in init stage */


/*-----------------------------------------------------------------------------------
In linux system there is no thread to record the module register information, So when
some error occur in a module register stage, than this module must undo all of action
which it had done in passed times,maybe use goto is a good way to recover the error
------------------------------------------------------------------------------------*/

/* but how can we detect the register error ?? */

int __init my_init_function(void)
{
    int err;
    /* usr pointer and name to register */
    err= register_this(ptr1, "skull");
    if(err) goto fail_this;
    err= register_that(ptr2, "skull");
    if(err) goto fail_that;
    err= regsiter_those(ptr3, "skull");
  
 
    return 0;
    fail_those: unregister_that(prt2, "skull");  /* why unregister that, because that
                                                  has registered sucessfully but those
                                                  was fail so module need unregister
                                                  the sucessful stepsl which as below:
                                                   1: that  ----second one
                                                   2: this  ----first one
                                                   3: return err number  */
    fail_that: unregister_this(prt1, "skull");
    fail_this: return err;

}















/*   This section aways bin put in the end of file at noadys */

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("kerhac");
MODULE_DESCRIPTION("testing module");
MODULE_VERSION("v0.1");
//MODULE_ALIAS(""); /* will discuss later will in chaper 11*/
//MODULE_DEVICE_TABLE("");   /* also discuss in chaper 12 */

 
  
  
  
  
  
