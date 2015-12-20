#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static struct lws *web_socket = NULL;

#define EXAMPLE_RX_BUFFER_BYTES (10)

static int callback_example( struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len )
{
	switch( reason )
	{
		case LWS_CALLBACK_CLIENT_ESTABLISHED:
			lws_callback_on_writable( wsi );
			break;

		case LWS_CALLBACK_CLIENT_RECEIVE:
			/* Handle incomming messages here. */
			break;

		case LWS_CALLBACK_CLIENT_WRITEABLE:
		{
			unsigned char buf[LWS_SEND_BUFFER_PRE_PADDING + EXAMPLE_RX_BUFFER_BYTES + LWS_SEND_BUFFER_POST_PADDING];
			unsigned char *p = &buf[LWS_SEND_BUFFER_PRE_PADDING];
			size_t n = sprintf( (char *)p, "%u", rand() );
			lws_write( wsi, p, n, LWS_WRITE_TEXT );
			break;
		}

		case LWS_CALLBACK_CLOSED:
		case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
			web_socket = NULL;
			break;

		default:
			break;
	}

	return 0;
}

enum protocols
{
	PROTOCOL_EXAMPLE = 0,
	PROTOCOL_COUNT
};

static struct lws_protocols protocols[] =
{
	{
		"example-protocol",
		callback_example,
		0,
		EXAMPLE_RX_BUFFER_BYTES,
	},
	{ NULL, NULL, 0, 0 } /* terminator */
};

int main( int argc, char *argv[] )
{
	struct lws_context_creation_info info;
	memset( &info, 0, sizeof(info) );

	info.port = CONTEXT_PORT_NO_LISTEN;
	info.protocols = protocols;
	info.gid = -1;
	info.uid = -1;

	struct lws_context *context = lws_create_context( &info );

	time_t old = 0;
	while( 1 )
	{
		struct timeval tv;
		gettimeofday( &tv, NULL );

		/* Connect if we are not connected to the server. */
		if( !web_socket && tv.tv_sec != old )
		{
			web_socket = lws_client_connect( /* context = */ context,
			                                 /* address = */ "localhost",
			                                 /* port = */ 8000,
			                                 /* ssl_connection = */ 0,
			                                 /* path = */ "/",
			                                 /* host = */ lws_canonical_hostname( context ),
			                                 /* origin = */ "origin",
			                                 /* protocol = */ protocols[PROTOCOL_EXAMPLE].name,
			                                 /* ietf_version_or_minus_one = */ -1 );
		}

		if( tv.tv_sec != old )
		{
			/* Send a random number to the server every second. */
			lws_callback_on_writable( web_socket );
			old = tv.tv_sec;
		}

		lws_service( context, 250 );
	}

	lws_context_destroy( context );

	return 0;
}
