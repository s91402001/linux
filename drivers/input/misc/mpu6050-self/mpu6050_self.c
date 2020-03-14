#include <linux/module.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/mutex.h>
#include <linux/sysfs.h>
#include <linux/printk.h>
#include <linux/pm_runtime.h>
#include <linux/delay.h>

static int mpu6050_i2c_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
    u8 device_address;
    int rc;

    rc = of_property_read_u8(client->dev.of_node, "reg", &device_address);
    printk("%s: reg value: %u, rc: %d\n", __func__, device_address, rc);

    return 0;
}

static int mpu6050_i2c_remove(struct i2c_client *client)
{
    printk("%s: removed\n", __func__);

    return 0;
}

static const struct i2c_device_id mpu6050_id[] = {
	{"mpu6050", 0},
	{}
};

MODULE_DEVICE_TABLE(i2c, mpu6050_id);


#ifdef CONFIG_OF_CONFIGFS
static struct of_device_id mpu6050_match_table[] = {
        { .compatible = "inv,mpu6050",},
        { },
};
#else
#define mpu6050_match_table NULL
#endif

static struct i2c_driver mpu6050_i2c_driver = {
 .driver = {
  .name = "mpu6050",
  .owner = THIS_MODULE,
  .of_match_table = of_match_ptr(mpu6050_match_table),
 },
 .probe =    mpu6050_i2c_probe,
 .remove =   mpu6050_i2c_remove,
 .id_table = mpu6050_id,
};

module_i2c_driver(mpu6050_i2c_driver);
MODULE_AUTHOR("Randy Chan");
MODULE_DESCRIPTION("MPU6050 self-learning driver");
MODULE_LICENSE("GPL");