RPCGEN= rpcgen
CC = gcc

CFLAGS =
RPCGENFLAGS =

all: build_rpc build_server build_client

build_rpc: rpcgen/whatsup.x
	@cd rpcgen; echo "Generate RPC files"; \
	$(RPCGEN) whatsup.x
	@cd ..;

build_server: rpcgen/whatsup.h rpcgen/whatsup_xdr.c rpcgen/whatsup_svc.c src/whatsup_server.c
	@echo "Build server"
	$(CC) rpcgen/whatsup_xdr.c rpcgen/whatsup_svc.c src/whatsup_server.c -o bin/server

build_client: rpcgen/whatsup.h rpcgen/whatsup_xdr.c rpcgen/whatsup_clnt.c src/whatsup_client.c
	@echo "Build client"
	$(CC) rpcgen/whatsup_xdr.c rpcgen/whatsup_clnt.c src/whatsup_client.c -o bin/client

remove_rpcgen_files: rpcgen/whatsup.h rpcgen/whatsup_xdr.c rpcgen/whatsup_svc.c rpcgen/whatsup_clnt.c
	@echo "Remove RPC files"
	rm rpcgen/whatsup.h rpcgen/whatsup_xdr.c rpcgen/whatsup_svc.c rpcgen/whatsup_clnt.c
