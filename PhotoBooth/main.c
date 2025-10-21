#include <stdio.h>
#include <time.h>
#include <gphoto2/gphoto2-camera.h>

int main() {
    Camera *camera;
    GPContext *context;
    int retval;

    context = gp_context_new();
    gp_camera_new(&camera);

    printf("Connecting to Nikon D90...\n");
    retval = gp_camera_init(camera, context);
    if (retval < GP_OK) {
        printf("❌ Camera not found!\n");
        return 1;
    }

    printf("✅ Camera connected! Capturing photo...\n");

    CameraFile *file;
    gp_file_new(&file);

    retval = gp_camera_capture(camera, GP_CAPTURE_IMAGE, &file, context);
    if (retval < GP_OK) {
        printf("❌ Capture failed!\n");
        return 1;
    }

    char filename[64];
    sprintf(filename, "photos/photo_%ld.jpg", time(NULL));
    gp_file_save(file, filename);

    printf("✅ Photo saved as %s\n", filename);

    gp_file_unref(file);
    gp_camera_exit(camera, context);
    gp_camera_unref(camera);
    gp_context_unref(context);

    return 0;
}
