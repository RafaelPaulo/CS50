build-img:
	docker build -f Dockerfile -t cs50 .

run-cs50:
	docker run -it cs50
