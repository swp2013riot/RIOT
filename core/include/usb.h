#ifndef USB_H
#define USB_H

/* this is the riot-os usb stack, have a lot of fun! */

#define USB_ENDPOINT_IN 0x80
#define USB_ENDPOINT_OUT 0x00

#define USB_REQUEST_TYPE_VENDOR (0x02 << 5)

#define USB_RECIPIENT_DEVICE 0x00

#define ANSWER 42

#endif /* USB_H */
