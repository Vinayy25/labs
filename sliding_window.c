#include <stdio.h>
void sender(void);
void reciever(void);
int frame = 0, ack = 0, frame_no = 1;
int lost_frame = 1, lost_ack = 2;
int seq_no = 0, ack_no = 0, timer = 0, ready = 1, max_frames = 3;
void main()
{
    while (frame_no <= max_frames)
    {
        sender();
        if (frame_no == lost_frame)
        {
            frame = 0;
            lost_frame = 0;
            printf("\nFrame%d has been lost\n", frame_no);
        }
        reciever();
        if (frame_no == lost_ack && ack == 1)
        {
            ack = 0;
            lost_ack = 0;
            printf("\nAck for frame%d has been lost\n", frame_no);
        }
        if (ack == 0)
        {
            printf("\nTimer has been expired\n");
            timer = 1; // time is expired
        }
    }
}
void sender(void)
{
    if (ready)
    {
        printf("\nFrame%d is sent with seq no %d\n", frame_no, seq_no);
        frame = 1;
        ready = 0;
        timer = 0; // indicates timer is started
    }
    else
    {
        if (timer == 1) // indicates timer is expired
        {
            printf("\nFrame%d is resent with seq no %d\n", frame_no, seq_no);
            frame = 1;
            timer = 0; // indicates timer is started
        }
        if (ack == 1)
        {
            printf("\nAck. for frame%d is recieved\n", frame_no);
            seq_no = !seq_no;
            ack = 0;
            frame_no = frame_no + 1;
            if (frame_no <= max_frames)
            {
                printf("\nFrame%d is sent with seq no %d\n", frame_no, seq_no);
                frame = 1;
                ready = 0;
                timer = 0; // indicates timer is started
            }
        }
    }
}
void reciever(void)
{
    if (frame == 1)
    {
        frame = 0; // frame has reached reciever
        if (ack_no == seq_no)
        {
            ack_no = !ack_no;
            printf("\nFrame%d is recieved and ack with ack.no. %d sent\n", frame_no, ack_no);
            ack = 1;
        }
        else
        {
           printf("\nFrame%d is duplicate and discarded. Ack with ack.no. %d has been sent\n",frame_no,ack_no);
		   ack=1;
        }
    }
}