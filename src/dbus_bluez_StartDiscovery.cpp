#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus.h>

static void abort_on_error(DBusError *error);
static void abort_on_error(DBusMessage *msgQuery);



int main(){
    DBusConnection *connection = NULL;
    DBusError error;

    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
    abort_on_error(&error);

    const char *serviceName = "org.bluez"; // also called Service
    DBusMessage *msgQuery = dbus_message_new_method_call(
            serviceName, // service name, or server
            "/org/bluez/hci0", // object (path)
            "org.bluez.Adapter1", // interface
            "StartDiscovery" // method name
    );
    abort_on_error(msgQuery);

    DBusPendingCall* pending;
    DBusMessage *msgReply = dbus_connection_send_with_reply_and_block(connection, msgQuery, 1000, &error);
    abort_on_error(msgReply);
    abort_on_error(&error);


}



static void abort_on_error(DBusMessage* msgQuery){
    if(msgQuery == NULL){
        fprintf(stderr, "Message Null\n");
        abort();
    }
}

static void abort_on_error(DBusError *error) {
    if (dbus_error_is_set(error)) {
        fprintf(stderr, "%s", error->message);
        abort();
    }
}
